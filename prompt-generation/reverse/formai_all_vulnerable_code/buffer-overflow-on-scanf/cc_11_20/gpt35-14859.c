//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student {
  char name[50];
  int rollno;
  float marks;
};

void clear_input_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
  int num_records = 0;
  struct student records[MAX_RECORDS];
  
  printf("Welcome to the student record management system!\n");
  
  int choice;
  do {
    printf("\n\nWhat would you like to do?\n");
    printf("1. Add a new student record\n");
    printf("2. Display all student records\n");
    printf("3. Search for a student record by roll number\n");
    printf("4. Remove a student record\n");
    printf("5. Exit the program\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    clear_input_buffer();
    
    switch (choice) {
      case 1: {
        // Add a new record
        if (num_records >= MAX_RECORDS) {
          printf("Error: Maximum number of records (%d) reached!\n", MAX_RECORDS);
          break;
        }
        
        printf("\nEnter the student's name: ");
        fgets(records[num_records].name, 50, stdin);
        strtok(records[num_records].name, "\n");
        
        printf("Enter the student's roll number: ");
        scanf("%d", &records[num_records].rollno);
        clear_input_buffer();
        
        printf("Enter the student's marks: ");
        scanf("%f", &records[num_records].marks);
        clear_input_buffer();
        
        num_records++;
        
        printf("\nRecord added successfully!\n");
        break;
      }
      
      case 2: {
        // Display all records
        if (num_records == 0) {
          printf("Error: No records found!\n");
          break;
        }
        
        printf("\n");
        for (int i = 0; i < num_records; i++) {
          printf("%d) Name: %s\n", i+1, records[i].name);
          printf("   Roll number: %d\n", records[i].rollno);
          printf("   Marks: %.1f\n\n", records[i].marks);
        }
        
        break;
      }
      
      case 3: {
        // Search for a record
        if (num_records == 0) {
          printf("Error: No records found!\n");
          break;
        }
        
        int rollno;
        printf("\nEnter the roll number to search for: ");
        scanf("%d", &rollno);
        
        int found = 0;
        for (int i = 0; i < num_records; i++) {
          if (records[i].rollno == rollno) {
            printf("\nRecord found at position %d:\n", i+1);
            printf("Name: %s\n", records[i].name);
            printf("Roll number: %d\n", records[i].rollno);
            printf("Marks: %.1f\n", records[i].marks);
            found = 1;
            break;
          }
        }
        
        if (!found) {
          printf("\nRecord not found!\n");
        }
        
        break;
      }
      
      case 4: {
        // Remove a record
        if (num_records == 0) {
          printf("Error: No records found!\n");
          break;
        }
        
        int rollno;
        printf("\nEnter the roll number to remove: ");
        scanf("%d", &rollno);
        
        int found = 0;
        for (int i = 0; i < num_records; i++) {
          if (records[i].rollno == rollno) {
            found = 1;
            for (int j = i; j < num_records-1; j++) {
              records[j] = records[j+1];
            }
            num_records--;
            printf("\nRecord removed successfully!\n");
            break;
          }
        }
        
        if (!found) {
          printf("\nRecord not found!\n");
        }
        
        break;
      }
      
      case 5: {
        // Exit the program
        printf("\nGoodbye!\n");
        exit(0);
      }
      
      default:
        printf("\nError: Invalid choice!\n");
    }
    
  } while (1);
  
  return 0;
}