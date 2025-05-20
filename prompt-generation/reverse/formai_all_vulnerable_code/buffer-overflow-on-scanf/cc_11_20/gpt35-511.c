//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char file_name[50];
    FILE *file_ptr;

    printf("Enter the name of the file you want to create: ");
    scanf("%s", file_name);
    
    int option = -1;
    do{
        printf("\nWhat do you want to do?\n");
        printf("\t1. Create a new file\n");
        printf("\t2. Write to the file\n");
        printf("\t3. Read from the file\n");
        printf("\t4. Append to the file\n");
        printf("\t5. Delete the file\n");
        printf("\t0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        printf("\n");

        switch(option){
            case 0: 
                printf("Goodbye!\n");
                break;
            case 1:
                file_ptr = fopen(file_name, "w");
                if(file_ptr == NULL){
                    printf("Unable to create file.\n");
                    break;
                }
                printf("File created successfully!\n");
                fclose(file_ptr);
                break;
            case 2:
                file_ptr = fopen(file_name, "w");
                if(file_ptr == NULL){
                    printf("Unable to open file.\n");
                    break;
                }
                char data[100];
                printf("Enter the data to write to file: ");
                getchar();
                fgets(data, sizeof(data), stdin);
                fputs(data, file_ptr);
                printf("Data written to file.\n");
                fclose(file_ptr);
                break;
            case 3:
                file_ptr = fopen(file_name, "r");
                if(file_ptr == NULL){
                    printf("Unable to open file.\n");
                    break;
                }
                char read_data[100];
                printf("Data in file:\n");
                while(fgets(read_data, sizeof(read_data), file_ptr)){
                    printf("%s", read_data);
                }
                printf("\n");
                fclose(file_ptr);
                break;
            case 4:
                file_ptr = fopen(file_name, "a");
                if(file_ptr == NULL){
                    printf("Unable to open file.\n");
                    break;
                }
                char append_data[100];
                printf("Enter the data to append to file: ");
                getchar();
                fgets(append_data, sizeof(append_data), stdin);
                fputs(append_data, file_ptr);
                printf("Data appended to file.\n");
                fclose(file_ptr);
                break;
            case 5:
                if(remove(file_name) == 0){
                    printf("File deleted successfully!\n");
                }else{
                    printf("Unable to delete file.\n");
                }
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }while(option != 0);

    return 0;
}