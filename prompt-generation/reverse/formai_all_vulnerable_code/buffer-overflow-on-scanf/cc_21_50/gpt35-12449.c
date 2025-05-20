//FormAI DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int n, i, j, k, s=1;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<i+1; j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<n; i++){
        for(j=n; j>i+1; j--){
            printf("  ");
        }
        for(k=0; k<i+1; k++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<n; i++){
        for(j=n; j>i+1; j--){
            printf("  ");
        }
        for(k=0; k<s; k++){
            printf("* ");
        }
        s+=2;
        printf("\n");
    }
    printf("\n");

    for(i=0; i<n; i++){
        for(j=n; j>i+1; j--){
            printf("  ");
        }
        for(k=0; k<2*i+1; k++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<n; i++){
        for(j=n; j>i+1; j--){
            printf("  ");
        }
        for(k=0; k<2*i+1; k++){
            if(k==0 || k==2*i || i==n-1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");

    s=-1;
    for(i=n; i>0; i--){
        for(j=i-1; j<n; j++){
            printf("  ");
        }
        for(k=2*i-1; k>s; k--){
            printf("* ");
        }
        s+=2;
        printf("\n");
    }
    printf("\n");

    s=1;
    for(i=0; i<n; i++){
        for(j=n; j>i+1; j--){
            printf("  ");
        }
        for(k=0; k<s; k++){
            if(k==0 || k==s-1 || i==n-1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        s+=2;
        printf("\n");
    }
    return 0;
}