//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    int i, n, choice, flag = 0;
    FILE *fp;

    fp = fopen("diary.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("diary.txt", "w");
    }

    printf("\nWelcome to your digital diary!\n");
    printf("Enter 'add' to add an entry, 'read' to read entries, or 'exit' to exit: ");
    scanf("%s", str);

    switch (str[0])
    {
        case 'a':
            printf("Enter your entry: ");
            scanf("%s", str);
            fprintf(fp, "%s\n", str);
            flag = 1;
            break;
        case 'r':
            printf("Your entries: \n");
            while (fgets(str, 100, fp) != NULL)
            {
                printf("%s\n", str);
            }
            break;
        case 'e':
            fclose(fp);
            exit(0);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    if (flag)
    {
        fclose(fp);
        printf("Entry added successfully!\n");
    }

    return 0;
}