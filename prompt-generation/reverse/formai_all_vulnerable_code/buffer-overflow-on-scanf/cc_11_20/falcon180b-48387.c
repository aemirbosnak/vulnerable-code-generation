//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int i,j,n,choice;
    char str[50],ch;
    printf("Enter a string: ");
    scanf("%s",str);
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printf("Enter the pattern:\n");
    printf("1. Increasing\n");
    printf("2. Decreasing\n");
    printf("3. Pyramid\n");
    printf("4. Inverted Pyramid\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    printf(" ");
                }
                for(j=0;j<2*i+1;j++){
                    printf("%c",str[j]);
                }
                printf("\n");
            }
            break;
        case 2:
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    printf(" ");
                }
                for(j=strlen(str)-1;j>=0;j--){
                    printf("%c",str[j]);
                }
                printf("\n");
            }
            break;
        case 3:
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    printf(" ");
                }
                for(j=0;j<=i*2;j++){
                    printf("%c",str[j]);
                }
                printf("\n");
            }
            break;
        case 4:
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    printf(" ");
                }
                for(j=strlen(str)-1;j>=0;j--){
                    printf("%c",str[j]);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}