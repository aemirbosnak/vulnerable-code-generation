//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include<stdio.h>
int main(){
    int choice, temp;
    float result;
    printf("Enter 0 to convert from Celsius to Fahrenheit\n");
    printf("Enter 1 to convert from Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 0){
        printf("Enter temperature in Celsius: ");
        scanf("%d", &temp);
        result = ((temp * 9) / 5) + 32;
        printf("%d Celsius is equal to %.2f Fahrenheit.", temp, result);
    }
    else if(choice == 1){
        printf("Enter temperature in Fahrenheit: ");
        scanf("%d", &temp);
        result = (float)(temp - 32) * 5 / 9;
        printf("%d Fahrenheit is equal to %.2f Celsius.", temp, result);
    }
    else{
        int i;
        char text[] = "Invalid choice. Please try again.\n";
        for(i = 0; i < strlen(text); i++){
            switch(text[i]){
                case 'I':
                    printf("1 ");
                    break;
                case 'n':
                    printf("2 ");
                    break;
                case 'v':
                    printf("4 ");
                    break;
                case 'a':
                    printf("3 ");
                    break;
                case 'l':
                    printf("7 ");
                    break;
                case 'i':
                    printf("9 ");
                    break;
                case 'd':
                    printf("6 ");
                    break;
                case 'c':
                    printf("8 ");
                    break;
                case 'h':
                    printf("5 ");
                    break;
                case '.':
                    printf("0 ");
                    break;
                case ' ':
                    printf("+ ");
                    break;
                case ':':
                    printf("- ");
                    break;
                case '\n':
                    printf("/ ");
                    break;
            }
        }
    }
    return 0;
}