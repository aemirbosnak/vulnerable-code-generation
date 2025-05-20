//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
// Welcome to 221B Baker Street, dear Watson. We shall embark on a visual adventure today, generating pixel art with the utmost precision.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Our canvas, where art shall take form
char *canvas;
int width, height;

// The tools of our trade: brushes and paints
typedef struct {
    int x, y;
    char symbol;
} Pixel;

// The masterstroke: painting our canvas
void paint_pixel(Pixel pixel) {
    if (pixel.x >= 0 && pixel.x < width && pixel.y >= 0 && pixel.y < height) {
        canvas[pixel.y * width + pixel.x] = pixel.symbol;
    }
}

// The mind palace: storing our masterpiece
void allocate_canvas(int w, int h) {
    width = w;
    height = h;
    canvas = malloc(width * height * sizeof(char));
    for (int i = 0; i < width * height; i++) {
        canvas[i] = ' ';
    }
}

// A brush dipped in mystery: single pixel placement
void draw_pixel(int x, int y, char symbol) {
    Pixel pixel = {x, y, symbol};
    paint_pixel(pixel);
}

// A stroke of brilliance: line drawing
void draw_line(int x1, int y1, int x2, int y2, char symbol) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    for (;;) {
        draw_pixel(x1, y1, symbol);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

// A web of intrigue: circle drawing
void draw_circle(int x, int y, int radius, char symbol) {
    int x0 = x, y0 = y;
    int err = radius - 1;
    int e2;
    do {
        Pixel pixel = {x0, y0, symbol};
        paint_pixel(pixel);
        e2 = (err << 2) + 1;
        if ((e2 >> 1) > err) { err--; x0--; }
        if ((err << 1) - e2 > err) { err--; y0--; }
        if (err <= 0) break;
    } while (x0 - x >= y - y0);
    draw_line(x, y, x, y0, symbol); // Special case for drawing the filled lower part of the circle
}

// The grand reveal: displaying our masterpiece
void print_canvas() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(canvas[i * width + j]);
        }
        putchar('\n');
    }
}

// Elementary, my dear Watson!
int main() {
    // Acquire the dimensions of our canvas
    printf("Enter the width and height of the canvas (separated by a space): ");
    scanf("%d %d", &width, &height);

    // Paint our blank canvas with the deepest of nights
    allocate_canvas(width, height);

    // Define our magnifying glass for close inspection
    int x, y;

    // Engage our deductive faculties to draw shapes
    printf("Your command, master Holmes? Enter 'pixel', 'line', or 'circle' to summon the appropriate tool: ");
    char command[20];
    while (scanf("%s", command) != EOF) {
        if (!strcmp(command, "pixel")) {
            printf("Inform me of the pixel's coordinates (x, y) and the symbol to etch: ");
            scanf("%d %d %c", &x, &y, &command[0]);
            draw_pixel(x, y, command[0]);
        } else if (!strcmp(command, "line")) {
            printf("Provide the coordinates of the line's endpoints (x1, y1) and (x2, y2): ");
            scanf("%d %d %d %d", &x, &y, &x, &y);
            draw_line(x, y, x, y, '#');
        } else if (!strcmp(command, "circle")) {
            printf("Inform me of the circle's center (x, y) and radius: ");
            scanf("%d %d %d", &x, &y, &x);
            draw_circle(x, y, x, '#');
        } else {
            printf("Invalid command. Try again, dear Watson.");
        }
    }

    // Display our solved case: the pixel art masterpiece
    print_canvas();

    // Tidying up our crime scene
    free(canvas);
    return 0;
}