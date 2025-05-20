//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_LENGTH 20

char file_system[MAX_FILES][MAX_FILE_LENGTH];
int num_files = 0;

void display_file_system(){
    printf("Current File System:\n");
    for(int i=0; i<num_files; i++){
        printf("%d. %s\n",i+1,file_system[i]);
    }
}

void add_file(char *file_name){
    if(num_files < MAX_FILES){
        strcpy(file_system[num_files],file_name);
        num_files++;
        printf("File %s added\n",file_name);
    }
    else{
        printf("Error: Maximum file limit reached\n");
    }    
}

void delete_file(char *file_name){
    int index = -1;
    for(int i=0; i<num_files; i++){
        if(strcmp(file_system[i],file_name)==0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Error: File not found\n");
    }
    else{
        for(int i=index; i<num_files-1; i++){
            strcpy(file_system[i],file_system[i+1]);
        }
        num_files--;
        printf("File %s deleted\n",file_name);
    }
}

int main(){
    int option = 0;
    char file_name[MAX_FILE_LENGTH];
    printf("Cyberpunk File System\n");

    do{
        printf("Enter 1 to add file, 2 to delete file, 3 to display file system, and 4 to exit: \n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                printf("Enter file name: ");
                scanf("%s",file_name);
                add_file(file_name);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s",file_name);
                delete_file(file_name);
                break;
            case 3:
                display_file_system();
                break;
            case 4:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid Option\n");
                break;
        }
    }while(option != 4);

    return 0;
}