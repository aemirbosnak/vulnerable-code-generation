//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_ADDR_LEN 64
#define MAX_LIST_SIZE 100

typedef struct
{
    char name[MAX_NAME_LEN];
    char addr[MAX_ADDR_LEN];
} mailing_entry_t;

typedef struct
{
    mailing_entry_t entries[MAX_LIST_SIZE];
    int size;
} mailing_list_t;

void mailing_list_init(mailing_list_t *list)
{
    list->size = 0;
}

int mailing_list_add(mailing_list_t *list, const char *name, const char *addr)
{
    if (list->size >= MAX_LIST_SIZE)
        return -1;  // List is full

    strcpy(list->entries[list->size].name, name);
    strcpy(list->entries[list->size].addr, addr);
    list->size++;

    return 0;
}

int mailing_list_remove(mailing_list_t *list, const char *name)
{
    int i;

    for (i = 0; i < list->size; i++)
    {
        if (strcmp(list->entries[i].name, name) == 0)
        {
            list->size--;
            memmove(&list->entries[i], &list->entries[i + 1],
                    (list->size - i) * sizeof(mailing_entry_t));
            return 0;  // Entry found and removed
        }
    }

    return -1;  // Entry not found
}

int mailing_list_find(mailing_list_t *list, const char *name)
{
    int i;

    for (i = 0; i < list->size; i++)
    {
        if (strcmp(list->entries[i].name, name) == 0)
            return i;  // Entry found
    }

    return -1;  // Entry not found
}

void mailing_list_print(mailing_list_t *list)
{
    int i;

    for (i = 0; i < list->size; i++)
    {
        printf("%s: %s\n", list->entries[i].name, list->entries[i].addr);
    }
}

int main()
{
    mailing_list_t list;
    int choice;
    char name[MAX_NAME_LEN], addr[MAX_ADDR_LEN];

    mailing_list_init(&list);

    while (1)
    {
        printf("\n1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Find entry\n");
        printf("4. Print list\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter address: ");
            scanf("%s", addr);
            if (mailing_list_add(&list, name, addr) == 0)
                printf("Entry added successfully\n");
            else
                printf("Error adding entry\n");
            break;
        case 2:
            printf("Enter name: ");
            scanf("%s", name);
            if (mailing_list_remove(&list, name) == 0)
                printf("Entry removed successfully\n");
            else
                printf("Error removing entry\n");
            break;
        case 3:
            printf("Enter name: ");
            scanf("%s", name);
            int index = mailing_list_find(&list, name);
            if (index >= 0)
                printf("Entry found at index %d\n", index);
            else
                printf("Entry not found\n");
            break;
        case 4:
            mailing_list_print(&list);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}