//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct knight{
    char name[20];
    char weapon[20];
    int prowess;
};

int main(){
    FILE *fp;
    int i,n,num;
    char fileName[20];
    struct knight k[10];
    
    srand(time(NULL));

    printf("Enter the name of file to be created: ");
    scanf("%s",fileName);

    fp=fopen(fileName,"w");

    if(fp==NULL){
        printf("File creation failed\n");
        exit(0);
    }

    printf("\nEnter the number of knights: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nKnight %d\n",i+1);
        printf("Enter the name of the knight: ");
        scanf("%s",k[i].name);

        printf("Enter the weapon of the knight: ");
        scanf("%s",k[i].weapon);

        k[i].prowess=rand()%10+1;
        
        printf("Prowess of the knight is: %d\n",k[i].prowess);

        fwrite(&k[i],sizeof(k[i]),1,fp);
    }

    fclose(fp);

    fp=fopen(fileName,"r");

    printf("\nEnter the knight number to be displayed: ");
    scanf("%d",&num);

    fseek(fp,(num-1)*sizeof(k[0]),SEEK_SET);
    fread(&k[num-1],sizeof(k[0]),1,fp);

    printf("\nData of knight %d\n",num);
    printf("Name: %s\n",k[num-1].name);
    printf("Weapon: %s\n",k[num-1].weapon);
    printf("Prowess: %d\n",k[num-1].prowess);

    fclose(fp);

    return 0;
}