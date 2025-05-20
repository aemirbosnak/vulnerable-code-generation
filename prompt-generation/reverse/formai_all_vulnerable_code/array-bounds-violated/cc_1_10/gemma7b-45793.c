//Gemma-7B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char email[1024];
    FILE *fp;

    fp = fopen("emails.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter your email address:");
    scanf("%s", email);

    while (fgets(buffer, 1024, fp) != NULL)
    {
        printf("%s", buffer);

        if (strstr(buffer, email) != NULL)
        {
            printf("This email is for you!\n");

            l = strlen(buffer) - 1;
            for (i = 0; i < l; i++)
            {
                if (buffer[i] == ':')
                {
                    n = i;
                    break;
                }
            }

            printf("Subject: ");
            for (j = n + 1; buffer[j] != '\n'; j++)
            {
                printf("%c", buffer[j]);
            }

            printf("\n");
            printf("Message: ");
            for (k = 0; buffer[k] != '\n'; k++)
            {
                printf("%c", buffer[k]);
            }

            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}