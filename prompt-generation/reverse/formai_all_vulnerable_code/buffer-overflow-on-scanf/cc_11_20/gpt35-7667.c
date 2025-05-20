//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include<stdio.h>
#define MAX_FILES 50 //Maximum number of files allowed

//Structure for file information
typedef struct File{
    char name[20];
    int size;
} File;

//Structure for directory information
typedef struct Directory{
    char name[20];
    int num_files; //Number of files in this directory
    File files[MAX_FILES]; //Array of files in this directory
} Directory;

//Main function
int main(){
    int num_dirs = 0; //Number of directories in the file system
    Directory dirs[MAX_FILES]; //Array of directories in the file system

    //Introduce the program
    printf("Welcome to the File System Simulator!\n");
    printf("This program allows you to create directories and add files to them.\n");

    //Start the loop
    while(1){
        //Print the options
        printf("\nOptions:\n");
        printf("1. Create a new directory\n");
        printf("2. Add a file to a directory\n");
        printf("3. List all directories and their files\n");
        printf("4. Exit\n");

        //Get the user's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Perform the chosen action
        if(choice == 1){
            //Create a new directory
            printf("\nEnter the name of the new directory: ");
            scanf("%s", dirs[num_dirs].name);
            dirs[num_dirs].num_files = 0;
            num_dirs++;
            printf("Directory created.\n");
        }
        else if(choice == 2){
            //Add a file to a directory
            if(num_dirs == 0){
                printf("\nThere are no directories to add a file to. Please create a directory first.\n");
                continue;
            }
            printf("\nDirectories:\n");
            for(int i=0; i<num_dirs; i++){
                printf("%d. %s (%d files)\n", i+1, dirs[i].name, dirs[i].num_files);
            }
            printf("Which directory would you like to add a file to? ");
            int dir_choice;
            scanf("%d", &dir_choice);
            if(dir_choice < 1 || dir_choice > num_dirs){
                printf("\nInvalid directory choice.\n");
                continue;
            }
            printf("Enter the name of the new file: ");
            scanf("%s", dirs[dir_choice-1].files[dirs[dir_choice-1].num_files].name);
            printf("Enter the size of the new file: ");
            scanf("%d", &dirs[dir_choice-1].files[dirs[dir_choice-1].num_files].size);
            dirs[dir_choice-1].num_files++;
            printf("File added.\n");
        }
        else if(choice == 3){
            //List all directories and their files
            printf("\nDirectories:\n");
            for(int i=0; i<num_dirs; i++){
                printf("%d. %s (%d files)\n", i+1, dirs[i].name, dirs[i].num_files);
                if(dirs[i].num_files > 0){
                    printf("   Files:");
                    for(int j=0; j<dirs[i].num_files; j++){
                        printf(" %s (%d bytes)", dirs[i].files[j].name, dirs[i].files[j].size);
                    }
                    printf("\n");
                }
            }
        }
        else if(choice == 4){
            //Exit the program
            printf("\nExiting...\n");
            break;
        }
        else{
            //Invalid choice
            printf("\nInvalid choice.\n");
        }
    }

    //End the program
    return 0;
}