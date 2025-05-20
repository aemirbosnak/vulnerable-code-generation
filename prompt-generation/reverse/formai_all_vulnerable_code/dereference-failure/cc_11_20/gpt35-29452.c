//FormAI DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

int main()
{
    int option, index = 0, i, j, deleteIndex = -1, flag = 0;
    char date[MAX], entry[MAX], temp[MAX], search[MAX];
    char *dates[MAX], *entries[MAX];

    while(1)
    {
        printf("\n\n--PARANOID DIGITAL DIARY--\n\n");
        printf("1. Add entry\n2. View all entries\n3. Search entry\n4. Delete entry\n5. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter date (DD/MM/YYYY): ");
                scanf("%s", date);
                printf("Enter entry: ");
                scanf(" %[^\n]", entry);

                //Storing date and entry
                dates[index] = (char*)malloc(sizeof(char)*(strlen(date)+1));
                entries[index] = (char*)malloc(sizeof(char)*(strlen(entry)+1));

                strcpy(dates[index], date);
                strcpy(entries[index], entry);

                index++;
                printf("\nEntry added successfully!\n");
                break;

            case 2:
                if(index == 0)
                {
                    printf("\nNo entries found.\n");
                    break;
                }

                printf("\nALL ENTRIES:\n");
                for(i=0; i<index; i++)
                {
                    printf("%d. DATE: %s\n", i+1, dates[i]);
                    printf("   ENTRY: %s\n\n", entries[i]);
                }
                break;

            case 3:
                if(index == 0)
                {
                    printf("\nNo entries found.\n");
                    break;
                }

                printf("\nEnter search keyword: ");
                scanf(" %[^\n]", search);

                printf("\nSEARCH RESULTS:\n");
                for(i=0; i<index; i++)
                {
                    flag = 0;

                    //Searching date and entry for keyword
                    if(strstr(dates[i], search) != NULL)
                    {
                        printf("%d. DATE: %s\n", i+1, dates[i]);
                        flag = 1;
                    }

                    if(strstr(entries[i], search) != NULL)
                    {
                        printf("%d. DATE: %s\n", i+1, dates[i]);
                        printf("   ENTRY: %s\n\n", entries[i]);
                        flag = 1;
                    }

                    if(flag == 0)
                    {
                        printf("No results found.\n");
                    }
                }
                break;

            case 4:
                if(index == 0)
                {
                    printf("\nNo entries found.\n");
                    break;
                }

                printf("\nEnter date (DD/MM/YYYY) of entry to be deleted: ");
                scanf("%s", date);

                for(i=0; i<index; i++)
                {
                    if(strcmp(dates[i], date) == 0)
                    {
                        deleteIndex = i;
                        break;
                    }
                }

                if(deleteIndex == -1)
                {
                    printf("Entry does not exist.\n");
                    break;
                }

                //Deleting entry
                for(j=deleteIndex; j<index-1; j++)
                {
                    strcpy(dates[j], dates[j+1]);
                    strcpy(entries[j], entries[j+1]);
                }

                free(dates[index-1]);
                free(entries[index-1]);

                index--;
                printf("\nEntry deleted.\n");
                break;

            case 5:
                //Freeing allocated memory before exit
                for(i=0; i<index; i++)
                {
                    free(dates[i]);
                    free(entries[i]);
                }

                printf("\nExiting program.\n");
                exit(0);

            default:
                printf("\nInvalid option.\n");
                break;
        }
    }
    return 0;
}