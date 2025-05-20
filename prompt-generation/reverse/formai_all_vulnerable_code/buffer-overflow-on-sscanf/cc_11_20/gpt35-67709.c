//FormAI DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000  // Maximum length for string inputs
#define MAX_RECORDS 10000       // Maximum number of records that can be stored
#define MAX_INDEX 26            // Maximum number of index positions (one for each letter of the alphabet)

typedef struct Record {
    char name[MAX_STRING_LENGTH];
    int age;
    float salary;
} Record;

typedef struct Index {
    char letter;
    int start;
    int end;
} Index;

int main() {
    Record records[MAX_RECORDS];
    Index index[MAX_INDEX];
    int num_records = 0;
    int num_index = 0;
    char input[MAX_STRING_LENGTH];
    char command;

    printf("Welcome to the Database Indexing System!\n");

    while (1) {
        printf("\nPlease enter a command:\n");
        fgets(input, MAX_STRING_LENGTH, stdin);
        sscanf(input, "%c", &command);

        switch (command) {
            case 'a': {
                // Add a new record
                Record new_record;

                printf("Enter the name: ");
                fgets(new_record.name, MAX_STRING_LENGTH, stdin);
                new_record.name[strcspn(new_record.name, "\n")] = 0; // Remove trailing newline character

                printf("Enter the age: ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                sscanf(input, "%d", &new_record.age);

                printf("Enter the salary: ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                sscanf(input, "%f", &new_record.salary);

                // Add the new record to the records array
                records[num_records] = new_record;
                num_records++;

                // Update the index
                int index_pos = new_record.name[0] - 'a';

                if (num_index == 0 || index[index_pos].letter != new_record.name[0]) {
                    // Add a new index position for this letter
                    Index new_index = {'\0', num_records - 1, num_records - 1};
                    new_index.letter = new_record.name[0];
                    index[num_index] = new_index;
                    num_index++;
                } else {
                    // Update the end position of the index for this letter
                    index[index_pos].end = num_records - 1;
                }

                printf("Record added successfully!\n");
                break;
            }

            case 's': {
                // Search for records by name
                printf("Enter the name: ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;

                int start = -1;
                int end = -1;
                int index_pos = input[0] - 'a';

                for (int i = 0; i < num_index; i++) {
                    if (index[i].letter == input[0]) {
                        start = index[i].start;
                        end = index[i].end;
                        break;
                    }
                }

                if (start == -1) {
                    printf("No records found!\n");
                    break;
                }

                printf("Results:\n");

                for (int i = start; i <= end; i++) {
                    if (strcmp(records[i].name, input) == 0) {
                        printf("Name: %s Age: %d Salary: %.2f\n", records[i].name, records[i].age, records[i].salary);
                    }
                }

                break;
            }

            case 'q': {
                // Quit the program
                printf("Goodbye!\n");
                exit(0);
            }

            default: {
                // Invalid command
                printf("Invalid command!\n");
            }
        }
    }

    return 0;
}