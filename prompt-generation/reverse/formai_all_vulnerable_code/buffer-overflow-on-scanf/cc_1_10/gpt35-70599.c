//FormAI DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILENAME1 "bob.txt"
#define FILENAME2 "alice.txt"

void silly_message()
{
    printf("\n\t>>> Welcome to the File Synchronizer! <<<\n");
    usleep(1000000);
    printf("\n\tAre you ready for some file synchronization madness?\n");
    usleep(1000000);
    printf("\n\tLet's do it!");
    usleep(1000000);
}

void copy_contents(FILE* file1, FILE* file2)
{
    char contents[1000];
    while (fgets(contents, 1000, file1))
    {
        fputs(contents, file2);
    }
}

void synchronize_files()
{
    FILE* file1;
    FILE* file2;
    char input;
    int option;

    while (1)
    {
        printf("\n\n\t\t>>> MENU <<<\n");
        printf("\n\t1. Sync %s to %s", FILENAME1, FILENAME2);
        printf("\n\t2. Sync %s to %s", FILENAME2, FILENAME1);
        printf("\n\t3. Quit");

        printf("\n\n\tEnter an option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                file1 = fopen(FILENAME1, "r");
                file2 = fopen(FILENAME2, "w");

                if (!file1 || !file2)
                {
                    printf("\n\tError: Files could not be opened.");
                    continue;
                }

                copy_contents(file1, file2);

                fclose(file1);
                fclose(file2);

                printf("\n\t%s synchronized to %s.", FILENAME1, FILENAME2);
                usleep(1000000);
                break;

            case 2:
                file1 = fopen(FILENAME2, "r");
                file2 = fopen(FILENAME1, "w");

                if (!file1 || !file2)
                {
                    printf("\n\tError: Files could not be opened.");
                    continue;
                }

                copy_contents(file1, file2);

                fclose(file1);
                fclose(file2);

                printf("\n\t%s synchronized to %s.", FILENAME2, FILENAME1);
                usleep(1000000);
                break;

            case 3:
                printf("\n\tExiting File Synchronizer...");
                return;

            default:
                printf("\n\tInvalid option. Please try again.");
                continue;
        }

        printf("\n\n\tPress any key to continue...");
        scanf(" %c", &input);
    }
}

int main()
{
    silly_message();
    synchronize_files();

    return 0;
}