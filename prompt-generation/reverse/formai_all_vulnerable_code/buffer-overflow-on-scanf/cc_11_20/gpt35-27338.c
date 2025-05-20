//FormAI DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char ch, temp;
    int choice, i, n;

    printf("1. Create a file\n");
    printf("2. View the content of a file\n");
    printf("3. Append content to a file\n");
    printf("4. Modify the content of a file\n");
    printf("5. Delete a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            //Creating a file
            fp = fopen("file.txt", "w");
            if(fp == NULL){
                printf("Error creating the file\n");
                exit(1);
            }
            printf("File created successfully\n");
            fclose(fp);
            break;
        case 2:
            //Viewing the content of a file
            fp = fopen("file.txt", "r");
            if(fp == NULL){
                printf("Error viewing the file\n");
                exit(1);
            }
            printf("The content of the file is:\n");
            ch = fgetc(fp);
            while(ch != EOF){
                printf("%c", ch);
                ch = fgetc(fp);
            }
            fclose(fp);
            break;
        case 3:
            //Appending content to a file
            fp = fopen("file.txt", "a");
            if(fp == NULL){
                printf("Error appending to the file\n");
                exit(1);
            }
            printf("Enter the number of characters you want to append: ");
            scanf("%d", &n);
            printf("Enter your text:\n");
            for(i = 0; i < n; i++){
                scanf("%c", &temp);
                fputc(temp, fp);
            }
            printf("Content appended successfully\n");
            fclose(fp);
            break;
        case 4:
            //Modifying the content of a file
            fp = fopen("file.txt", "r+");
            if(fp == NULL){
                printf("Error modifying the file\n");
                exit(1);
            }
            printf("Enter the character you want to modify: ");
            scanf(" %c", &temp);
            printf("Enter the new character: ");
            scanf(" %c", &ch);
            while((temp = fgetc(fp)) != EOF){
                if(temp == ch){
                    fseek(fp, -1, SEEK_CUR);
                    fputc(ch, fp);
                }
            }
            printf("Content modified successfully\n");
            fclose(fp);
            break;
        case 5:
            //Deleting a file
            if(remove("file.txt") == 0){
                printf("File deleted successfully\n");
            } else {
                printf("Error deleting the file\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}