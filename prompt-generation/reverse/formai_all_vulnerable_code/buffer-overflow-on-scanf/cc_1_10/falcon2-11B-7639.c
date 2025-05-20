//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display menu options
void display_menu() {
    printf("1. Create Exam\n");
    printf("2. View Exam\n");
    printf("3. Mark Exam\n");
    printf("4. Generate Report\n");
    printf("5. Exit\n");
}

// Function to create exam
void create_exam() {
    // Code to create exam
}

// Function to view exam
void view_exam() {
    // Code to view exam
}

// Function to mark exam
void mark_exam() {
    // Code to mark exam
}

// Function to generate report
void generate_report() {
    // Code to generate report
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_exam();
                break;
            case 2:
                view_exam();
                break;
            case 3:
                mark_exam();
                break;
            case 4:
                generate_report();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}