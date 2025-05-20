//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Artistic Greedy Algorithm Example!\n");
    printf("In this example, we will create a painting using the Greedy Algorithm.\n");
    printf("We will first take input from the user for the size of the painting (in inches).\n");
    printf("Enter the length of the painting in inches: ");
    float length;
    scanf("%f", &length);
    printf("Enter the width of the painting in inches: ");
    float width;
    scanf("%f", &width);
    float area = length * width;
    printf("\nThe area of the painting is %.2f square inches.\n", area);

    printf("\nNext, we will choose the colors for the painting.\n");
    printf("Enter the number of available colors: ");
    int numColors;
    scanf("%d", &numColors);
    char** colors = (char**)malloc(numColors * sizeof(char*));
    for(int i=0; i<numColors; i++){
        colors[i] = (char*)malloc(10 * sizeof(char));
        printf("Enter the name of color %d: ", i+1);
        scanf("%s", colors[i]);
    }

    int numSquares = (int)area;
    char* canvas = (char*)malloc(numSquares * sizeof(char));
    int* colorCounts = (int*)calloc(numColors, sizeof(int));
    for(int i=0; i<numSquares; i++){
        int maxIndex = 0;
        for(int j=1; j<numColors; j++){
            if(colorCounts[j] > colorCounts[maxIndex]){
                maxIndex = j;
            }
        }
        canvas[i] = maxIndex;
        colorCounts[maxIndex]++;
    }

    printf("\nThe painting is complete! Here is the color scheme:\n");
    for(int i=0; i<numColors; i++){
        printf("%s: %d squares\n", colors[i], colorCounts[i]);
    }

    free(canvas);
    free(colorCounts);
    for(int i=0; i<numColors; i++){
        free(colors[i]);
    }
    free(colors);

    printf("\nThanks for using the Artistic Greedy Algorithm Example!");

    return 0;
}