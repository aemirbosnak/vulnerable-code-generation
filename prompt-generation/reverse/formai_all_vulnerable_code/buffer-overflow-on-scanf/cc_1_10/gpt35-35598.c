//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include<stdio.h>

void fractal(char drawing[50][50], int start, int end, int gap, int level){
    if(level == 0){
        for(int i=start; i<end; i++){
            for(int j=gap; j<gap+level+2; j++){
                drawing[i][j] = '*';
            }
        }
        return;
    }
    
    int mid = (start + end) / 2;
    fractal(drawing, start, mid, gap, level-1);
    fractal(drawing, mid, end, gap+level+1, level-1);
    
    for(int i=start; i<mid; i++){
        for(int j=gap; j<gap+level+2; j++){
            drawing[i][j] = drawing[i][2*mid-j+gap-2];
        }
    }
}

int main(){
    char drawing[50][50];
    int size, level;
    
    printf("Enter the size (a power of 2, max 8): ");
    scanf("%d", &size);
    printf("Enter the level (max %d): ", size-1);
    scanf("%d", &level);
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size-level; j++){
            drawing[i][j] = ' ';
        }
        drawing[i][size-level] = '*';
    }
    
    fractal(drawing, 0, size, 0, level);
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size-level; j++){
            printf("%c", drawing[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}