//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recoverData(char *filename){
    FILE *fp;
    int i,j,flag=0;
    char data[100],key[50],*p;

    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("ERROR: File not found!\n");
        exit(1);
    }

    printf("Enter key to decrypt data: ");
    scanf("%s",key);

    while(fgets(data,100,fp)!=NULL){
        i=0;
        while(data[i]!='\0'){
            j=0;
            p=&data[i];
            while(key[j]==*p && j<strlen(key)){
                j++;
                p++;
            }
            if(j==strlen(key)){
                printf("%s",p);
                flag=1;
            }
            i++;
        }
    }

    if(flag==0){
        printf("No data found!");
    }

    fclose(fp);
}

int main(){
    char filename[50];

    printf("Enter filename to recover data: ");
    scanf("%s",filename);

    recoverData(filename);

    return 0;
}