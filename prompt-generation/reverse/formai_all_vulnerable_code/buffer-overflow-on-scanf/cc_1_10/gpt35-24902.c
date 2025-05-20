//FormAI DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_disk(char *filename){
    FILE *fp;
    char ch;
    int i, size;
    fp = fopen(filename, "r");
    
    if(fp == NULL){
        printf("Error in opening file!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    
    printf("Data read from disk:\n\n");
    
    for(i=0;i<size;i++){
        ch = fgetc(fp);
        printf("%c", ch);
    }
    printf("\n\n");
    fclose(fp);
}

void write_disk(char *filename, char *data){
    FILE *fp;
    int size;
    fp = fopen(filename, "w");
    
    if(fp == NULL){
        printf("Error in opening file!\n");
        exit(1);
    }
    
    size = strlen(data);
    fwrite(data, size, sizeof(char), fp);
    
    printf("Data written to disk:\n\n%s\n", data);
    fclose(fp);
}

void recover_disk(char *filename){
    FILE *fp;
    char buffer[255];
    int i;
    
    fp = fopen(filename, "r");
    
    if(fp == NULL){
        printf("Error in opening file!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    if(ftell(fp) == 0){
        printf("Disk is empty!\n");
        fclose(fp);
        return;
    }
    rewind(fp);
    
    printf("Enter the buffer size: ");
    scanf("%d", &i);
    
    printf("Data recovered from disk:\n\n");
    while(!feof(fp)){
        fgets(buffer, i, fp);
        printf("%s", buffer);
    }
    printf("\n");
    fclose(fp);
}

int main(){
    char filename[30];
    char data[255];
    int option;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    while(1){
        printf("\nSelect an option:\n");
        printf("1. Read data from disk\n");
        printf("2. Write data to disk\n");
        printf("3. Recover data from disk\n");
        printf("4. Exit\n");
        
        scanf("%d", &option);
        
        switch(option){
            case 1: read_disk(filename);
                    break;
            case 2: printf("Enter the data: ");
                    scanf("%s", data);
                    write_disk(filename, data);
                    break;
            case 3: recover_disk(filename);
                    break;
            case 4: printf("Exiting program!\n");
                    exit(0);
            default: printf("Invalid option!\n");
        }
    }
    return 0;
}