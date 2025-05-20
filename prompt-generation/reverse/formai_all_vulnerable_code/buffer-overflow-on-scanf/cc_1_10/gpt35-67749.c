//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate and print random pixel art
void pixel_gen(int size) {
    // Initialize random seed
    srand(time(NULL));
  
    // Display size of pixel art
    printf("Size of pixel art: %d x %d\n", size, size);
  
    // Loop to generate pixel art
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            // Generate random number between 0 and 3
            int num = rand() % 4;
            // Print corresponding pixel character based on random number
            switch(num) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("%c", 219);
                    break;
                case 2:
                    printf("%c", 176);
                    break;
                case 3:
                    printf("%c", 178);
                    break;
                default:
                    break;
            }
        }
        // Move to next line after printing row of pixels
        printf("\n");
    }
}

int main() {
    int size;
  
    // Get size of pixel art from user
    printf("Enter size of pixel art: ");
    scanf("%d", &size);
  
    // Generate and print pixel art
    pixel_gen(size);
  
    return 0;
}