//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {

    char name[30], entry[100];
    time_t curtime;
    struct tm *loc_time;
    char time_str[20];
    FILE *file;
    int choice, count=0;

    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("\n\nYou have opened your digital diary. What do you want to do?\n");
    printf("1. Make an entry\n");
    printf("2. Read previous entries\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter your entry (Maximum 100 characters): ");
            scanf(" %[^\n]s", entry);
            file = fopen(name, "a");
            if(file == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            curtime = time(NULL);
            loc_time = localtime(&curtime);
            strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", loc_time);
            fprintf(file, "%s:\n%s\n\n", time_str, entry);
            printf("\n\nEntry added successfully!\n\n");
            fclose(file);
            break;

        case 2:
            file = fopen(name, "r");
            if(file == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            printf("\n\n********** Your previous entries **********\n\n");
            while(fgets(entry, sizeof(entry), file) != NULL) {
                printf("%s", entry);
                count++;
            }
            printf("\n\n********** End of diary **********\n");
            if(count == 0)
                printf("\n\nYou have not made any entries yet!\n\n");
            fclose(file);
            break;

        case 3:
            printf("\n\nExiting from your digital diary...\n\n");
            exit(0);
            break;

        default:
            printf("\n\nInvalid choice, please try again!\n\n");
            main();
    }

    main();
}