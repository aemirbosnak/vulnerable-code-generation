//FormAI DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

void printA(int height, int width) {
    int mid = width/2 + 1;
    for(int i=0; i<height; i++) {
        for(int j=1; j<=width; j++) {
            if((j==1 || j==width) && i!=0 || i==height/2 && j>1 && j<mid ||
               j==mid && i!=0 && i!=height/2 || i==0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printB(int height, int width) {
    for(int i=0; i<height; i++) {
        for(int j=1; j<=width; j++) {
            if((j==1 || j==width) && i!=height-1 || i==height-1 && j>1 && j<width ||
               j==height && i>height/2 && i<height-1 || i==height/2 && j>height/2 && j<width-1 ||
               i<height/2 && j==width-1-i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printC(int height, int width) {
    for(int i=0; i<height; i++) {
        for(int j=1; j<=width; j++) {
            if(i==0 && j!=1 || i==height-1 && j!=1 || j==1 && i!=0 && i!=height-1 ||
               i==j && i>height/2 && j<width || i+j==height+1 && i>height/2 && j>1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int height, width, choice;
    printf("Enter the height and width of the pattern: ");
    scanf("%d %d", &height, &width);
    printf("Which pattern do you want to print: \n1. A\n2. B\n3. C\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: printA(height, width);
                break;
        case 2: printB(height, width);
                break;
        case 3: printC(height, width);
                break;
        default: printf("Invalid choice");
    }
    return 0;
}