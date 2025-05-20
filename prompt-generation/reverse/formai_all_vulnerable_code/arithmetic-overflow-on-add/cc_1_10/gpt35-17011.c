//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include<stdio.h>
#include<time.h>

void write_to_file(char *path, char *data) {
    FILE *file;
    file = fopen(path, "a");
    if (file == NULL)
        printf("Unable to open the file\n");
    else {
        fprintf(file, "%s", data);
        fclose(file);
    }
}

void display_file(char *path) {
    FILE *file;
    char ch;
    file = fopen(path, "r");

    if (file == NULL)
        printf("Unable to open the file\n");
    else {
        while ((ch = fgetc(file)) != EOF)
            printf("%c", ch);
        fclose(file);
    }
}

void main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char *path = "diary.txt";
    char data[500];
    char response;
    int choice;

    printf("Welcome to your digital diary!\n");
    printf("Today is %d/%d/%d.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    do {
        printf("\n1. Write to diary\n2. View diary\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your thoughts: ");
                fflush(stdin);
                fgets(data, 500, stdin);

                write_to_file(path, "\n");
                write_to_file(path, data);

                printf("Successfully added to diary!\n");
                break;
            case 2:
                printf("\n\n*** Diary entries ***\n\n");
                display_file(path);
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (Y/N): ");
        fflush(stdin);
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');
}