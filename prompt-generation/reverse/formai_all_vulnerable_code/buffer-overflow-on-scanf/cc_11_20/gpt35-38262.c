//FormAI DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct file
{
    char fname[MAX];
    int size;
    char content[MAX];
};

int main()
{
    int ch, i;
    char fname[MAX];
    struct file f[MAX];
    int n=0, total_size=0; 

    while (1)
    {
        printf("\n\n\t\t\t File System Simulation \n");
        printf("\t\t\t -------------------------- \n");

        printf("1. Create a new file\n2. View all files\n3. Search a file\n4. Delete a file\n5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter file name: ");
                scanf("%s", fname);
                printf("\nEnter file size (in kB): ");
                scanf("%d", &f[n].size);
                total_size += f[n].size;

                if (total_size > MAX)
                {
                    printf("\nMemory limit exceeded! File cannot be created.\n");
                    total_size -= f[n].size;
                    break;
                }

                strcpy(f[n].fname, fname);
                printf("\nEnter file content: ");
                scanf("%s", f[n].content);
                n++;

                printf("\nFile created successfully!\n");
                break;

            case 2:
                if(n==0)
                {
                    printf("\nNo files found!\n");
                    break;
                }

                printf("\nDetails of the files:\n");

                for(i=0; i<n; i++)
                {
                    printf("%d. Name: %s | Size: %d kB\n", i+1, f[i].fname, f[i].size);
                }
                break;

            case 3:
                if(n==0)
                {
                    printf("\nNo files found!\n");
                    break;
                }

                printf("\nEnter file name to search: ");
                scanf("%s", fname);

                for(i=0; i<n; i++)
                {
                    if(strcmp(f[i].fname, fname)==0)
                    {
                        printf("\nFile found! Details:\n");
                        printf("Name: %s | Size: %d kB | Content: %s\n", f[i].fname, f[i].size, f[i].content);
                        break;
                    }
                }

                if(i==n)
                {
                    printf("\nFile not found!\n");
                }
                break;

            case 4:
                if(n==0)
                {
                    printf("\nNo files found!\n");
                    break;
                }

                printf("\nEnter file name to delete: ");
                scanf("%s", fname);

                for(i=0; i<n; i++)
                {
                    if(strcmp(f[i].fname, fname)==0)
                    {
                        total_size -= f[i].size;
                        printf("\nFile deleted successfully!\n");

                        for(int j=i; j<n-1; j++)
                        {
                            f[j] = f[j+1];
                        }

                        n--;
                        break;
                    }
                }

                if(i==n)
                {
                    printf("\nFile not found!\n");
                }
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    }

    return 0;
}