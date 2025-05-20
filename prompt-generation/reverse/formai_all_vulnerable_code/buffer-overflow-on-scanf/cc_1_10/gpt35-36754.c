//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void new_entry(char* file_name);
void view_entries(char* file_name);

int main(int argc, char** argv) {
    char* file_name = "diary.txt";
    int choice = 0;
    while (choice != 3) {
        printf("\nWelcome to your Digital Diary!\n");
        printf("What would you like to do?\n");
        printf("1. Add new entry\n");
        printf("2. View existing entries\n");
        printf("3. Exit\n");
        printf("Your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                new_entry(file_name);
                break;
            case 2:
                view_entries(file_name);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void new_entry(char* file_name) {
    FILE* file = fopen(file_name, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter your new entry (press enter twice to finish):\n");
    char buffer[256] = {0};
    char c = getchar(); // Read newline character from previous input
    while ((c = getchar()) != '\n') { // Ignore first newline character
        int i = 0;
        while (c != '\n' && i < 255) {
            buffer[i++] = c;
            c = getchar();
        }
        buffer[i] = '\n';
        buffer[i + 1] = '\0';
        fputs(buffer, file);
    }
    printf("Your new entry has been added to your diary!\n");
    fclose(file);
}

void view_entries(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    int entry_counter = 1;
    char buffer[256] = {0};
    while (!feof(file)) {
        fgets(buffer, 255, file);
        if (buffer[0] != '\n') { // Ignore empty lines
            printf("%d. %s", entry_counter++, buffer);
        }
        memset(buffer, 0, 256*sizeof(char));
    }
    fclose(file);
}