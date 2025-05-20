//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> 

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20

int num_of_files = 0;
char files[MAX_FILES][MAX_NAME_LENGTH];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* Function to synchronize the files */
void *sync_files(void *thread_args)
{
    int i;
    char current_file[MAX_NAME_LENGTH];
    strcpy(current_file, (char*)thread_args);
    
    /* Critical section */
    pthread_mutex_lock(&mutex);
    for(i=0;i<num_of_files;i++)
    {
        if(strcmp(current_file, files[i]) != 0)
        {
            printf("Syncing %s with %s\n", current_file, files[i]);
            /* Code to synchronize files */
        }
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{
    int option;
    char new_file[MAX_NAME_LENGTH];
    pthread_t thread_id;

    while(1)
    {
        printf("Select an option:\n");
        printf("1. Add a file\n");
        printf("2. Remove a file\n");
        printf("3. Synchronize files\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter file name: ");
                scanf("%s", new_file);
                if(num_of_files == MAX_FILES)
                {
                    printf("Maximum number of files reached\n");
                    break;
                }
                strcpy(files[num_of_files], new_file);
                num_of_files++;
                printf("File added successfully\n");
                break;
            case 2:
                if(num_of_files == 0)
                {
                    printf("No files to remove\n");
                    break;
                }
                printf("Enter file name to remove: ");
                scanf("%s", new_file);
                for(int i=0;i<num_of_files;i++)
                {
                    if(strcmp(new_file, files[i]) == 0)
                    {
                        printf("%s removed successfully\n", new_file);
                        num_of_files--;
                        /* Shift all file names after the removed file to the left */
                        for(int j=i;j<num_of_files;j++)
                        {
                            strcpy(files[j], files[j+1]);
                        }
                        break;
                    }
                }
                break;
            case 3:
                for(int i=0;i<num_of_files;i++)
                {
                    pthread_create(&thread_id, NULL, sync_files, (void*)files[i]);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}