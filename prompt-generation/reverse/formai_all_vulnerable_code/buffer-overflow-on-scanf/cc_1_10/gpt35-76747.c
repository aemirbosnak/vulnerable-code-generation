//FormAI DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <time.h>

int main() {

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);

    FILE *file;
    char fileName[32];
    sprintf(fileName, "diary-%02d-%02d-%04d.txt", tm->tm_mday, tm->tm_mon + 1 , tm->tm_year + 1900);
    file = fopen(fileName, "a+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nHello! Welcome to your digital diary.\n");
    printf("Today's date is: %s\n\n", s);
    printf("1. Write to your diary.\n");
    printf("2. Read your diary.\n");
    printf("3. Exit.\n");

    int choice;
    scanf("%d", &choice);

    while (choice != 3) {

        switch(choice) {

            case 1:
                printf("\nEnter your entry: \n");
                
                char buffer[1000];
                scanf(" %[^\n]s", buffer);
                fprintf(file, "%s\n", buffer);
                
                printf("\nEntry saved successfully! \n");
                printf("1. Write to your diary.\n");
                printf("2. Read your diary.\n");
                printf("3. Exit.\n");
                scanf("%d", &choice);

                break;

            case 2:
                printf("\nYour diary entries for %s are:\n", s);

                char line[1024];
                while (fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
                
                printf("\n");
                printf("1. Write to your diary.\n");
                printf("2. Read your diary.\n");
                printf("3. Exit.\n");
                scanf("%d", &choice);

                break;
            
            default:
                printf("\nInvalid option. Please try again.\n");
                printf("1. Write to your diary.\n");
                printf("2. Read your diary.\n");
                printf("3. Exit.\n");
                scanf("%d", &choice);
                break;
        }   
    }
    
    printf("\nThank you for using your digital diary. Goodbye!\n");
    fclose(file);
    return 0;
}