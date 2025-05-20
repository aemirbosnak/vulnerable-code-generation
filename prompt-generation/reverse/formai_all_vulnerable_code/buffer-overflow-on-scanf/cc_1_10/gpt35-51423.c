//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include<stdio.h>
#include<string.h>

int main(){

    FILE *fp;
    char fileName[20], newFileName[20], data[50], newData[50], searchStr[20];
    int choice=0, i=0, count=0;
    long int position=0, fileSize=0; 

    printf("Enter the name of file: ");
    gets(fileName);

    fp = fopen(fileName,"w"); //Opening File in Write Mode

    if(fp == NULL){
        printf("Error in opening file!");
        return 1;
    }
    else{
        printf("File created successfully.");
    }

    printf("\nEnter data to be saved in file: ");
    gets(data);

    fprintf(fp, "%s", data);

    fclose(fp);

    printf("\nDo you want to rename the file? (1 for Yes/0 for No): ");
    scanf("%d",&choice);

    if(choice){

        printf("\nEnter new file name: ");
        scanf("%s",newFileName);

        if(rename(fileName,newFileName)){
            printf("Error in renaming file!");
            return 1;
        }
        else{
            printf("\nFile renamed successfully.");
        }
    }

    printf("\nDo you want to search for a string in file? (1 for Yes/0 for No): ");
    scanf("%d",&choice);

    if(choice){

        printf("\nEnter the string to search: ");
        scanf("%s",searchStr);

        fp = fopen(newFileName,"r");

        if(fp == NULL){
            printf("Error in opening file!");
            return 1;
        }

        fseek(fp, 0L, SEEK_END); //Moving the File Pointer to End of File

        fileSize = ftell(fp); //Calculating Size of File

        while(position < fileSize){

            fseek(fp, position, SEEK_SET); //Moving the File Pointer to Position

            fgets(newData, 50, fp); //Reading Line from File

            if(strstr(newData,searchStr) != NULL){
                printf("\nString found at line %d: %s",i,newData);
                count++;
            }

            position = ftell(fp); //Updating New Position

            i++; //Updating Line Counter

        }

        printf("\n%d matching lines found.",count);

        fclose(fp);
    }

    return 0;
}