//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  srand(time(NULL)); // Seed the random number generator
  int nums[10]; // Create an array of size 10 to store integers
  for(int i=0; i<10; i++) {
    nums[i] = rand() % 100; // Fill the array with random integers between 0 and 99
  }

  // Print the array in a visually appealing way
  printf("╔════════════════════════════════════════╗\n");
  printf("║        C Data Structures Visualizer      ║\n");
  printf("╠════════════════════════════════════════╣\n");
  printf("║                                          ║\n");
  printf("║                 Array                    ║\n");
  printf("║              ----------                  ║\n");
  printf("║          | %2d | %2d | %2d | %2d | %2d |          ║\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
  printf("║          ----------                      ║\n");
  printf("║       | %2d | %2d | %2d | %2d | %2d | %2d | %2d |     ║\n", nums[5], nums[6], nums[7], nums[8], nums[9], nums[10], nums[11]);
  printf("║          ----------                      ║\n");
  printf("║                                          ║\n");
  printf("╚════════════════════════════════════════╝\n");
  sleep(3); // Pause for 3 seconds
  printf("\033[H\033[J"); // Clear the screen
  printf("Now sorting the array...\n");
  sleep(3);
  
  // Use the bubble sort algorithm to sort the array
  for(int i=0; i<10; i++) {
    for(int j=0; j<9-i; j++) {
      if(nums[j] > nums[j+1]) {
        int temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
        
        // Reprint the array after each swap
        printf("╔════════════════════════════════════════╗\n");
        printf("║        C Data Structures Visualizer      ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║                                          ║\n");
        printf("║                 Array                    ║\n");
        printf("║              ----------                  ║\n");
        printf("║          | %2d | %2d | %2d | %2d | %2d |          ║\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
        printf("║          ----------                      ║\n");
        printf("║       | %2d | %2d | %2d | %2d | %2d | %2d | %2d |     ║\n", nums[5], nums[6], nums[7], nums[8], nums[9], nums[10], nums[11]);
        printf("║          ----------                      ║\n");
        printf("║                                          ║\n");
        printf("╚════════════════════════════════════════╝\n");
        sleep(1);
        printf("\033[H\033[J"); // Clear the screen
      }
    }
  }
  
  // Print the sorted array
  printf("The array has been sorted.\n");
  printf("Sorted array: ");
  for(int i=0; i<10; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  
  return 0;
}