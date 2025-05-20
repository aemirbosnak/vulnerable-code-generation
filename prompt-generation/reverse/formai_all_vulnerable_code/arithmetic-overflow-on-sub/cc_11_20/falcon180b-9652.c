//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[100];
    int rating;
}movie;

int main(){
    int n,i,j,choice;
    movie m[100];
    char ch[100];
    printf("Enter the number of movies:");
    scanf("%d",&n);
    printf("Enter the names of movies:\n");
    for(i=0;i<n;i++){
        scanf("%s",m[i].name);
    }
    printf("Enter the ratings of movies:\n");
    for(i=0;i<n;i++){
        scanf("%d",&m[i].rating);
    }
    printf("Enter the choice:\n1.Sort by name\n2.Sort by rating\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            for(i=0;i<n-1;i++){
                for(j=i+1;j<n;j++){
                    if(strcmp(m[i].name,m[j].name)>0){
                        strcpy(ch,m[i].name);
                        strcpy(m[i].name,m[j].name);
                        strcpy(m[j].name,ch);
                    }
                }
            }
            printf("Sorted by name:\n");
            for(i=0;i<n;i++){
                printf("%s %d\n",m[i].name,m[i].rating);
            }
            break;
        }
        case 2:{
            for(i=0;i<n-1;i++){
                for(j=i+1;j<n;j++){
                    if(m[i].rating>m[j].rating){
                        int temp=m[i].rating;
                        m[i].rating=m[j].rating;
                        m[j].rating=temp;
                    }
                }
            }
            printf("Sorted by rating:\n");
            for(i=0;i<n;i++){
                printf("%s %d\n",m[i].name,m[i].rating);
            }
            break;
        }
        default:{
            printf("Invalid choice!");
            exit(0);
        }
    }
    return 0;
}