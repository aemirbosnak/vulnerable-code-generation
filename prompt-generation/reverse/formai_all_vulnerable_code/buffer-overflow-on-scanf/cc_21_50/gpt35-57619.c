//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include<stdio.h>

int main() {

    int size = 10, pattern;
    printf("Enter the pattern you want to print:\n");
    scanf("%d", &pattern);
    printf("Enter the size of the pattern:\n");
    scanf("%d", &size);

    for(int i=0; i<=size; i++) {

        for(int j=0; j<=size; j++) {

            switch(pattern) { // Configurable pattern style

                case 1: 
                    if((i+j)<=size/2) printf("*"); // Pattern #1
                    else printf(" ");
                    break;

                case 2: 
                    if((j<i && j<size-i) || (j>size-i && j>i)) printf("*"); // Pattern #2
                    else printf(" ");
                    break;

                case 3: 
                    if((i+j)%3==0) printf("*"); // Pattern #3
                    else printf(" ");
                    break;

                case 4: 
                    if(i%2==0 && (j==0 || j==size)) printf("*"); // Pattern #4
                    else if(i%2!=0 && (j>0 && j<size)) printf("*");
                    else printf(" ");
                    break;

                case 5: 
                    if((i==0 || i==size/2 || i==size) && (j>0 && j<size)) printf("*"); // Pattern #5
                    else if((j==0 || j==size) && (i>0 && i<size)) printf("*");
                    else printf(" ");
                    break;
                    
                default:
                    printf("Invalid Choice!");
            }
        }
        printf("\n");
    }

    return 0;
}