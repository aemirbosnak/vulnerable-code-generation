//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[10], color[10], code[10];
    int i;
    
    printf("Enter the color (red, blue, green, yellow, magenta, cyan): ");
    scanf("%s", input);
    
    // convert input to lowercase for easier string comparison
    for(i = 0; i < strlen(input); i++){
        input[i] = tolower(input[i]);
    }
    
    if(strcmp(input, "red") == 0){
        strcpy(color, "Red");
        strcpy(code, "#ff0000");
    }
    else if(strcmp(input, "blue") == 0){
        strcpy(color, "Blue");
        strcpy(code, "#0000ff");
    }
    else if(strcmp(input, "green") == 0){
        strcpy(color, "Green");
        strcpy(code, "#00ff00");
    }
    else if(strcmp(input, "yellow") == 0){
        strcpy(color, "Yellow");
        strcpy(code, "#ffff00");
    }
    else if(strcmp(input, "magenta") == 0){
        strcpy(color, "Magenta");
        strcpy(code, "#ff00ff");
    }
    else if(strcmp(input, "cyan") == 0){
        strcpy(color, "Cyan");
        strcpy(code, "#00ffff");
    }
    else{
        printf("Invalid input! Please enter a valid color.\n");
        return 0;
    }
    
    printf("Color: %s\nCode: %s\n", color, code);
    
    return 0;
}