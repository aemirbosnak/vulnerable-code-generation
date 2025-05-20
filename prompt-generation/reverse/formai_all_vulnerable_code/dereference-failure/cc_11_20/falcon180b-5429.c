//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    time_t timestamp;
    char *text;
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    char buffer[1000];
    time_t now;
    struct entry entry;
    int choice, index;

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error opening diary file. Exiting...\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n2. Read entries\n3. Search for an entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry:\n");
                fgets(buffer, 1000, stdin);
                entry.timestamp = time(NULL);
                entry.text = strdup(buffer);
                fseek(diary, 0L, SEEK_END);
                fprintf(diary, "%s\n", buffer);
                fclose(diary);
                diary = fopen(filename, "a+");
                if (diary == NULL) {
                    printf("Error opening diary file. Exiting...\n");
                    exit(1);
                }
                break;

            case 2:
                printf("\nEntries:\n");
                rewind(diary);
                while (fgets(buffer, 1000, diary)!= NULL) {
                    printf("%s", buffer);
                }
                break;

            case 3:
                printf("Enter keyword to search for:\n");
                scanf("%s", buffer);
                rewind(diary);
                while (fgets(buffer, 1000, diary)!= NULL) {
                    if (strstr(buffer, buffer)!= NULL) {
                        printf("%s", buffer);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}