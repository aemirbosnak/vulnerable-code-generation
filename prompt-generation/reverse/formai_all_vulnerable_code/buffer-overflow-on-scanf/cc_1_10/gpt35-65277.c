//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASS_LEN 100    // max password length
#define HASH_TABLE_SIZE 100 // hash table size

// password struct
typedef struct password
{
    char site[50];
    char username[50];
    char pass[MAX_PASS_LEN];
    struct password *next;
} password;

// hash table struct
typedef struct hash_table
{
    password *head;
    int count;
} hash_table;

// hash function
int hash(char *site)
{
    int hash = 0;
    int len = strlen(site);
    int i;

    for (i = 0; i < len; i++)
    {
        hash += (int)site[i]; // sum the ascii values of the characters
    }

    return hash % HASH_TABLE_SIZE;
}

// create a new password node
password *new_password(char *site, char *username, char *pass)
{
    password *newNode = malloc(sizeof(password));
    newNode->next = NULL;
    strcpy(newNode->site, site);
    strcpy(newNode->username, username);
    strcpy(newNode->pass, pass);
    return newNode;
}

// insert a new password into the hash table
void insert_password(hash_table *ht, char *site, char *username, char *pass)
{
    int idx = hash(site);
    password *newNode = new_password(site, username, pass);

    if (!ht[idx].head)
    {
        ht[idx].head = newNode;
        ht[idx].count++;
        return;
    }

    password *temp = ht[idx].head;

    // check if site already exists
    while (temp != NULL)
    {
        if (strcmp(temp->site, site) == 0)
        {
            printf("Site already exists in password list.\n");
            return;
        }
        temp = temp->next;
    }

    // site does not exist, add new password node to hash table
    temp = ht[idx].head;
    ht[idx].head = newNode;
    newNode->next = temp;
    ht[idx].count++;
}

// display all passwords in the hash table
void display_passwords(hash_table *ht)
{
    int i;

    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        printf("Index %d:\n", i);

        if (!ht[i].head)
        {
            printf("No passwords in this index.\n");
        }
        else
        {
            password *temp = ht[i].head;

            while (temp != NULL)
            {
                printf("Site: %s\n", temp->site);
                printf("Username: %s\n", temp->username);
                printf("Password: %s\n\n", temp->pass);
                temp = temp->next;
            }
        }
    }
}

// search for a password in the hash table
password *search_password(hash_table *ht, char *site)
{
    int idx = hash(site);

    if (!ht[idx].head)
    {
        printf("Site not found in password list.\n");
        return NULL;
    }
    else
    {
        password *temp = ht[idx].head;

        while (temp != NULL)
        {
            if (strcmp(temp->site, site) == 0)
            {
                printf("Site: %s\n", temp->site);
                printf("Username: %s\n", temp->username);
                printf("Password: %s\n", temp->pass);
                return temp;
            }
            temp = temp->next;
        }

        printf("Site not found in password list.\n");
        return NULL;
    }
}

// generate a random password
void generate_password(char *pass)
{
    int i, r;
    char c;

    // set random seed based on time
    srand(time(NULL));

    // generate random password characters
    for (i = 0; i < MAX_PASS_LEN; i++)
    {
        r = rand() % 62; // 26 uppercase, 26 lowercase, 10 digits
        if (r < 26)
            c = 'A' + r;
        else if (r < 52)
            c = 'a' + (r - 26);
        else
            c = '0' + (r - 52);
        pass[i] = c;
    }

    pass[MAX_PASS_LEN - 1] = '\0';
}

int main()
{
    hash_table ht[HASH_TABLE_SIZE] = {0};
    char site[50], username[50], pass[MAX_PASS_LEN];
    int choice;

    while (1)
    {
        printf("\nPassword Manager:\n");
        printf("1. Add new password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter site name: ");
            scanf("%s", site);
            printf("Enter username: ");
            scanf("%s", username);
            generate_password(pass);
            insert_password(ht, site, username, pass);
            printf("Password for %s has been added to list.\n", site);
            break;

        case 2:
            display_passwords(ht);
            break;

        case 3:
            printf("\nEnter site name to search: ");
            scanf("%s", site);
            search_password(ht, site);
            break;

        case 4:
            printf("\nExiting program.\n");
            exit(0);

        default:
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}