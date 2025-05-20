//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include<stdio.h>

void top(int num) {
    int i,j,k;
    for(i=1; i<=num; i++) {
        for(j=i; j<num; j++) {
            printf(" ");
        }
        for(k=1; k<=(2*i-1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void middle(int num) {
    int i;
    for(i=1; i<=num/3; i++) {
        printf("*");
        int j;
        for(j=1; j<=(num-2); j++) {
            printf(" ");
        }
        printf("*\n");
    }
}

void bottom(int num) {
    int i,j,k;
    for(i=num/3; i>=1; i--) {
        for(j=num/3; j>i; j--) {
            printf(" ");
        }
        printf("*");
        for(k=1; k<=(2*i-3); k++) {
            printf(" ");
        }
        printf("*\n");
    }
}

void shapeshift(int h, int w) {
    int i,j;
    for(i=1; i<h; i++) {
        top(w);
    }
    middle(w);
    for(i=1; i<h; i++) {
        bottom(w);
    }
}

int main() {
    int height, width;
    printf("Enter height and width:\n");
    scanf("%d %d",&height,&width);
    shapeshift(height,width);
    return 0;
}