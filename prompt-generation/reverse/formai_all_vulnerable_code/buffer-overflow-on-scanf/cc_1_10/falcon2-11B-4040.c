//Falcon2-11B DATASET v1.0 Category: Game ; Style: retro
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    int score = 0;
    
    printf("Welcome to Retro Game!\n");
    printf("Press any key to start the game.\n");
    getchar();
    
    while (score < 100) {
        printf("Score: %d\n", score);
        printf("Press 1 to shoot a missile.\n");
        printf("Press 2 to increase score by 10.\n");
        printf("Press 3 to increase score by 50.\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Missile shot!\n");
                score += 10;
                break;
            case 2:
                printf("Score increased by 10!\n");
                score += 10;
                break;
            case 3:
                printf("Score increased by 50!\n");
                score += 50;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        
        printf("Press any key to continue.\n");
        getchar();
    }
    
    printf("Congratulations! You won the game!\n");
    
    printf("Press any key to calculate the area of a circle.\n");
    getchar();
    
    printf("Enter the radius of the circle: ");
    int radius;
    scanf("%d", &radius);
    
    printf("Area of the circle: %.2f\n", PI * radius * radius);
    
    return 0;
}