//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n,i,j,k,l,m;
    char a[100],b[100],c[100];
    int count=0;
    int flag=0;
    srand(time(0));
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the name of disk %d: ",i+1);
        scanf("%s",&a[i]);
    }
    printf("\n");
    for(i=n;i>=1;i--){
        for(j=0;j<n-i;j++){
            printf("%c",32);
        }
        printf("%c",219);
        for(k=0;k<i-1;k++){
            printf("%c",32);
        }
        printf("%c",220);
        for(l=0;l<n-i;l++){
            printf("%c",32);
        }
        printf("\n");
    }
    printf("\n");
    printf("Tower of Hanoi\n");
    printf("Move disk %d from %s to %s\n",n,a[0],c[0]);
    system("sleep 1");
    for(i=n;i>=1;i--){
        for(j=0;j<n-i;j++){
            printf("%c",32);
        }
        printf("%c",219);
        for(k=0;k<i-1;k++){
            printf("%c",32);
        }
        printf("%c",220);
        for(l=0;l<n-i;l++){
            printf("%c",32);
        }
        printf("\n");
    }
    printf("\n");
    for(i=n-1;i>=0;i--){
        for(j=0;j<n-i;j++){
            printf("%c",32);
        }
        printf("%c",219);
        for(k=0;k<n-i-1;k++){
            printf("%c",32);
        }
        printf("%c",220);
        for(l=0;l<n-i;l++){
            printf("%c",32);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++){
        printf("Move disk %d from %s to %s\n",i,a[i-1],c[i-1]);
        system("sleep 1");
        for(j=0;j<n-i;j++){
            printf("%c",32);
        }
        printf("%c",219);
        for(k=0;k<i-1;k++){
            printf("%c",32);
        }
        printf("%c",220);
        for(l=0;l<n-i;l++){
            printf("%c",32);
        }
        printf("\n");
    }
    for(i=n-1;i>=0;i--){
        printf("Move disk %d from %s to %s\n",i+1,c[i],b[i]);
        system("sleep 1");
        for(j=0;j<n-i;j++){
            printf("%c",32);
        }
        printf("%c",219);
        for(k=0;k<n-i-1;k++){
            printf("%c",32);
        }
        printf("%c",220);
        for(l=0;l<n-i;l++){
            printf("%c",32);
        }
        printf("\n");
    }
    return 0;
}