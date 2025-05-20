//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int i = 0, n = 0, flag = 0;
    FILE *fp;

    fp = fopen("digital_diary.txt", "w");
    fprintf(fp, "Welcome to your digital diary!\n");

    while (1)
    {
        printf("Enter 'a' to add an entry, 'r' to read entries, 'e' to edit entries, or 'q' to quit: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'a':
                printf("Enter your entry: ");
                scanf(" %[^\n]", n);
                fprintf(fp, "Entry %d: %s\n", n, n);
                break;

            case 'r':
                printf("Here are your entries:\n");
                fp = fopen("digital_diary.txt", "r");
                while ((ch = fgetc(fp)) != EOF)
                {
                    printf("%c", ch);
                }
                fclose(fp);
                break;

            case 'e':
                printf("Enter the number of the entry you want to edit: ");
                scanf(" %d", &n);
                printf("Enter your new entry: ");
                scanf(" %[^\n]", n);
                fp = fopen("digital_diary.txt", "w");
                fprintf(fp, "Welcome to your digital diary!\n");
                for (i = 0; i < n; i++)
                {
                    fprintf(fp, "Entry %d: %s\n", i + 1, n);
                }
                fclose(fp);
                break;

            case 'q':
                flag = 1;
                break;
        }

        if (flag)
        {
            break;
        }
    }

    fclose(fp);

    return 0;
}