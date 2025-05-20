//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 200
#define MAX_DURATION_MINUTES 300

struct exercise {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int duration_minutes;
};

int main() {
    FILE *fptr;
    struct exercise exercises[MAX_EXERCISES];
    int num_exercises = 0;
    int choice;
    char filename[MAX_NAME_LEN];
    time_t now;
    char timestring[MAX_DESCRIPTION_LEN];

    printf("Welcome to the Fitness Tracker!\n\n");
    printf("Please enter a filename to save your data:\n");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (1) {
        printf("\n\nFitness Tracker Menu:\n");
        printf("1. Add an exercise\n");
        printf("2. View exercises\n");
        printf("3. Save data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_exercises >= MAX_EXERCISES) {
                printf("Maximum number of exercises reached.\n");
                break;
            }
            printf("Enter the name of the exercise (up to %d characters): ", MAX_NAME_LEN - 1);
            scanf("%s", exercises[num_exercises].name);
            printf("Enter a description of the exercise (up to %d characters): ", MAX_DESCRIPTION_LEN - 1);
            scanf("%s", exercises[num_exercises].description);
            printf("Enter the duration of the exercise in minutes (up to %d): ", MAX_DURATION_MINUTES);
            scanf("%d", &exercises[num_exercises].duration_minutes);
            num_exercises++;
            break;
        case 2:
            printf("\nList of exercises:\n");
            for (int i = 0; i < num_exercises; i++) {
                printf("%s - %s - %d minutes\n", exercises[i].name, exercises[i].description, exercises[i].duration_minutes);
            }
            break;
        case 3:
            time(&now);
            strftime(timestring, MAX_DESCRIPTION_LEN, "%Y-%m-%d %H:%M:%S", localtime(&now));
            printf("Data saved to file: %s\n", timestring);
            fclose(fptr);
            exit(0);
        case 4:
            printf("Exiting program...\n");
            fclose(fptr);
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}