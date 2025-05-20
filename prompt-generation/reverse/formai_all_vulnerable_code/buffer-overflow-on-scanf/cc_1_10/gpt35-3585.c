//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct password {
    char website[100];
    char username[50];
    char pass[50];
};

int main()
{
    int n, i, j, k, check = 0;
    printf("How many passwords you want to store? ");
    scanf("%d", &n);

    struct password p[n];

    for(i=0; i<n; i++)
    {
        printf("\nEnter website name: ");
        scanf("%s", p[i].website);

        printf("Enter username: ");
        scanf("%s", p[i].username);

        printf("Enter password: ");
        scanf("%s", p[i].pass);
    }

    printf("\nEnter website to get password: ");
    char website[100];
    scanf("%s", website);

    for(i=0; i<n; i++)
    {
        if(strcmp(p[i].website, website) == 0)
        {
            printf("\nPassword found!\n");
            printf("Website: %s\n", p[i].website);
            printf("Username: %s\n", p[i].username);
            printf("Password: %s\n", p[i].pass);
            check = 1;
            break;
        }
    }

    if(check == 0)
    {
        printf("\nPassword not found!\n");
    }

    return 0;
}