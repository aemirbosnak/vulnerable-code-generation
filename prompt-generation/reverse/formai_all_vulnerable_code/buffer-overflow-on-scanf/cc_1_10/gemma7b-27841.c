//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, n = 0, choice = 0, a = 1, b = 2;
    char ch;
    FILE *fp;

    fp = fopen("diary.txt", "w");
    fprintf(fp, "Welcome to your digital diary!\n");

    while (1)
    {
        printf("Enter 1 to write, 2 to read, 3 to edit, or 4 to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("What do you want to write? ");
                scanf("%[^\n]%*c", ch);
                fprintf(fp, "%c\n", ch);
                break;
            case 2:
                printf("Your diary entries:\n");
                fp = fopen("diary.txt", "r");
                while ((ch = fgetc(fp)) != EOF)
                {
                    printf("%c", ch);
                }
                fclose(fp);
                break;
            case 3:
                printf("Enter the entry you want to edit: ");
                scanf("%[^\n]%*c", ch);
                fp = fopen("diary.txt", "r");
                a = 1;
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == ch)
                    {
                        printf("Enter your revised entry: ");
                        scanf("%[^\n]%*c", ch);
                        fprintf(fp, "%c", ch);
                        a = 0;
                    }
                    else
                    {
                        fprintf(fp, "%c", ch);
                    }
                }
                fclose(fp);
                break;
            case 4:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid input.\n");
                break;
        }
    }
}