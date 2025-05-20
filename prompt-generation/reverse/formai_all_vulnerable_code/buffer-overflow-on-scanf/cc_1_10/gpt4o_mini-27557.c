//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_LINE_LEN 256
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float grade;
} Student;

void clear_buffer() {
    while (getchar() != '\n') { }
}

int read_csv(const char *filename, Student *students) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char line[MAX_LINE_LEN];
    int count = 0;

    // Skip the header line (if present)
    fgets(line, sizeof(line), file);

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file) && count < MAX_STUDENTS) {
        sscanf(line, "%[^,],%d,%f", students[count].name, &students[count].age, &students[count].grade);
        count++;
    }

    fclose(file);
    return count;
}

void display_students(Student *students, int count) {
    printf("\nList of Students:\n");
    printf("%-20s %-5s %-6s\n", "Name", "Age", "Grade");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-6.2f\n", students[i].name, students[i].age, students[i].grade);
    }
    printf("-------------------------------------\n");
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Read CSV File\n");
    printf("2. Display Students\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    char filename[100];

    do {
        display_menu();
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                printf("Enter CSV file name to read (e.g., students.csv): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                count = read_csv(filename, students);
                if (count > 0) {
                    printf("Successfully read %d students from %s.\n", count, filename);
                } else {
                    printf("Failed to read students from the specified file.\n");
                }
                break;
            
            case 2:
                if (count > 0) {
                    display_students(students, count);
                } else {
                    printf("No students to display. Please read a CSV file first.\n");
                }
                break;
            
            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}