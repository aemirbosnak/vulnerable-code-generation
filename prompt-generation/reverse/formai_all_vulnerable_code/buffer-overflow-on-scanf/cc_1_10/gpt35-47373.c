//FormAI DATASET v1.0 Category: Memory management ; Style: Claude Shannon
/* 
   This C program demonstrates dynamic memory allocation in a Shannon style.
   Memory chunks are allocated to a football game attendance record and the 
   data is printed out in a randomized order to preserve privacy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct attendance_record {
  int game_id;
  int num_attendees;
  float ticket_price;
  char *location;
};

int main() {
  srand(time(NULL)); // Random seed for data shuffling
  
  int num_records;
  printf("Enter the number of games: ");
  scanf("%d", &num_records);
  
  struct attendance_record *records;
  records = (struct attendance_record *) malloc(num_records * sizeof(struct attendance_record));
  
  // Memory allocation error check
  if (records == NULL) {
    printf("Memory allocation error.\n");
    exit(1);
  }
  
  // Fill in the record details for each game
  for (int i = 0; i < num_records; i++) {
    printf("\nGame %d:\n", i+1);
    
    // Randomly generated data for privacy preservation
    (records + i)->game_id = rand();
    (records + i)->num_attendees = rand();
    (records + i)->ticket_price = ((float) rand()/(float) (RAND_MAX)) * 100 + 20; // Ticket price between $20 and $120
    (records + i)->location = NULL;
    
    // Allocate memory for the location string
    (records + i)->location = (char *) malloc(50 * sizeof(char));
    
    // Memory allocation error check
    if ((records + i)->location == NULL) {
      printf("Memory allocation error.\n");
      exit(1);
    }
    
    printf("Enter the location of the game: ");
    scanf("%s", (records + i)->location);
  }
  
  // Print out the record details in a randomized order
  printf("\nAttendance Records:\n");
  int i = 0;
  while (i < num_records) {
    int random_index = rand() % num_records;
    if ((records + random_index)->game_id != -1) {
      printf("\nGame %d:\n", random_index+1);
      printf("Location: %s\n", (records + random_index)->location);
      printf("Number of Attendees: %d\n", (records + random_index)->num_attendees);
      printf("Ticket Price: $%.2f\n", (records + random_index)->ticket_price);      
      (records + random_index)->game_id = -1; // Mark the record as printed
      i++;
    }
  }
  
  // Free up memory allocated to the location strings
  for (int i = 0; i < num_records; i++) {
    free((records + i)->location);
  }
  
  // Free up the memory allocated to the record struct
  free(records);
  
  return 0;
}