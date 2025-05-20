//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct question{
    char q[200];
    char a[100];
    char b[100];
    char c[100];
    char d[100];
    char ans;
};

int main(){
    int i,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z;
    char ch;
    struct question qs[10];
    FILE *fp;
    char filename[20];
    int score=0;
    char name[20];
    printf("Enter your name: ");
    scanf("%s",name);
    printf("\nWelcome %s to the Online Examination System",name);
    printf("\nEnter the name of the file containing the questions: ");
    scanf("%s",filename);
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("\nError: File not found");
        exit(0);
    }
    for(i=0;i<10;i++){
        fscanf(fp,"%s",qs[i].q);
        qs[i].ans=0;
        for(j=0;j<4;j++){
            fscanf(fp,"%s",qs[i].a);
            qs[i].ans++;
        }
        qs[i].ans++;
    }
    fclose(fp);
    printf("\n\nQuestion Paper:\n");
    for(i=0;i<10;i++){
        printf("%d. %s\n",i+1,qs[i].q);
        printf("\n");
        for(j=0;j<4;j++){
            printf("%c. %s\n",'a'+j,qs[i].a[j]);
        }
        printf("\n");
    }
    printf("\n\nEnter your answers:\n");
    for(i=0;i<10;i++){
        scanf("%c",&ch);
        if(ch=='a'||ch=='A'){
            if(qs[i].ans==1){
                printf("\nCorrect answer\n");
                score++;
            }
            else{
                printf("\nIncorrect answer\n");
            }
        }
        else if(ch=='b'||ch=='B'){
            if(qs[i].ans==2){
                printf("\nCorrect answer\n");
                score++;
            }
            else{
                printf("\nIncorrect answer\n");
            }
        }
        else if(ch=='c'||ch=='C'){
            if(qs[i].ans==3){
                printf("\nCorrect answer\n");
                score++;
            }
            else{
                printf("\nIncorrect answer\n");
            }
        }
        else if(ch=='d'||ch=='D'){
            if(qs[i].ans==4){
                printf("\nCorrect answer\n");
                score++;
            }
            else{
                printf("\nIncorrect answer\n");
            }
        }
    }
    printf("\n\nYour score is: %d out of 10",score);
    return 0;
}