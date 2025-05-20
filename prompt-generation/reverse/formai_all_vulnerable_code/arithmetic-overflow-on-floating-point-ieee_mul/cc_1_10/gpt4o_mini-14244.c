//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculate_distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void display_distance(float distance) {
    if (distance < 1.0) {
        printf("Their hearts beat closely, but just out of reach: %f units apart.\n", distance);
    } else if (distance < 5.0) {
        printf("A mere few steps, they are but whispers away: %f units apart.\n", distance);
    } else {
        printf("Alas, an eternal divide between them: %f units, love's cruel distance!\n", distance);
    }
}

void romeo_approaches(Point romeo, Point juliet) {
    printf("As Romeo gazes upon Juliet from afar...\n");
    printf("Stars align at coordinates (%.2f, %.2f) for Romeo,\n", romeo.x, romeo.y);
    printf("while fair Juliet awaits at (%.2f, %.2f).\n", juliet.x, juliet.y);
    
    float distance = calculate_distance(romeo, juliet);
    printf("Oh, sweet distance, what dost thou reveal?\n");
    
    display_distance(distance);
    
    printf("Romeo ponders:\n");
    if (distance < 3.0) {
        printf("A distance so small, let me not waste this chance!\n");
    } else if (distance < 10.0) {
        printf("Oh, to traverse this space, my heart doth ache!\n");
    } else {
        printf("How cruel, Fate! To keep us worlds apart!\n");
    }
}

int main() {
    Point romeo = {3.0, 4.0};
    Point juliet = {7.0, 9.0};

    printf("In fair Verona, where we lay our scene...\n");
    
    romeo_approaches(romeo, juliet);
    
    return 0;
}