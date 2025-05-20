//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX 1024

void analyze_email(char *email)
{
    char *subject, *body, *from, *to, *cc, *bcc;
    int i, flag = 0;

    subject = strchr(email, "Subject:");
    if (subject)
    {
        subject++;
        for (i = 0; subject[i] && i < MAX; i++)
        {
            if (subject[i] >= 'a' && subject[i] <= 'z')
            {
                flag = 1;
            }
        }
    }

    body = strstr(email, "Body:");
    if (body)
    {
        body++;
        for (i = 0; body[i] && i < MAX; i++)
        {
            if (body[i] >= 'a' && body[i] <= 'z')
            {
                flag = 1;
            }
        }
    }

    from = strchr(email, "From:");
    if (from)
    {
        from++;
        for (i = 0; from[i] && i < MAX; i++)
        {
            if (from[i] >= 'a' && from[i] <= 'z')
            {
                flag = 1;
            }
        }
    }

    if (flag)
    {
        printf("Spam detected!\n");
    }
    else
    {
        printf("Not spam.\n");
    }
}

int main()
{
    char email[MAX];

    printf("Enter email: ");
    gets(email);

    analyze_email(email);

    return 0;
}