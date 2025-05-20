//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void surreal_color_conversion(int r, int g, int b) {
    int max = r > g ? (r > b ? r : b) : (g > b ? g : b);
    
    float r_norm = (float)r / max;
    float g_norm = (float)g / max;
    float b_norm = (float)b / max;

    // Surreal transformation of the color
    float surreal_red   = (r_norm * r_norm * 0.5) + 0.5;
    float surreal_green = (g_norm + 1.5) * 0.3 - 0.1;
    float surreal_blue  = (b_norm + 0.3) * (1 - r_norm);
    
    printf("Behold, post-transformation colors emerge:\n");
    printf("Sublime Red:   %f\n", surreal_red);
    printf("Gleeful Green: %f\n", surreal_green);
    printf("Bizarre Blue:  %f\n", surreal_blue);
    
    printf("In the world of emotions:\n");
    if (surreal_red > 0.5) {
        printf("- A passionate flame ignites.\n");
    } else {
        printf("- A calm river flows.\n");
    }
    
    if (surreal_green > 0.5) {
        printf("- A forest of dreams awakens.\n");
    } else {
        printf("- Shadows linger in the twilight.\n");
    }
    
    if (surreal_blue > 0.5) {
        printf("- A heavenly sky unfolds.\n");
    } else {
        printf("- The depths of the ocean whisper.\n");
    }
}

void elusive_input_prompt() {
    printf("An echoing darkness surrounds you...\n");
    printf("Enter an RGB color in the realm of 0 to 255, as if summoning the colors from the void:\n");
    printf("R: ");
}

int main() {
    int r, g, b;

    elusive_input_prompt();
    scanf("%d", &r);
    
    printf("G: ");
    scanf("%d", &g);
    
    printf("B: ");
    scanf("%d", &b);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Ah! The colors elude thee! They must be confined between 0 to 255.\n");
        return 1;
    }

    printf("In the labyrinth of colors, you chose: (%d, %d, %d)\n", r, g, b);
    
    surreal_color_conversion(r, g, b);
    
    printf("The world has been altered by your choice. Colors merge and meld like thoughts beneath the veil of consciousness.\n");
    printf("Press Enter to dissolve into the next dimension...\n");
    getchar(); // Consume newline left by previous input
    getchar(); // Wait for user to press Enter

    return 0;
}