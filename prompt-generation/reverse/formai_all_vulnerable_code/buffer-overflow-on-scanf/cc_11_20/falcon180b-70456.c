//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX_SIZE 100

int main(){
    char input[MAX_SIZE];
    char *token;
    int i;
    double num1, num2, result;
    int choice;
    char repeat;
    do{
        printf("Enter the expression: ");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, " ");
        while(token!= NULL){
            if(isdigit(token[0])){
                num1 = atof(token);
            }else{
                switch(token[0]){
                    case '+':
                        num1 = num2 + atof(strtok(NULL, " "));
                        break;
                    case '-':
                        num1 = num2 - atof(strtok(NULL, " "));
                        break;
                    case '*':
                        num1 = num2 * atof(strtok(NULL, " "));
                        break;
                    case '/':
                        if(atof(strtok(NULL, " ")) == 0){
                            printf("Error! Division by zero.\n");
                            exit(0);
                        }
                        num1 = num2 / atof(strtok(NULL, " "));
                        break;
                    case '^':
                        num1 = pow(num2, atof(strtok(NULL, " ")));
                        break;
                    case's':
                        srand(time(0));
                        num1 = rand() % atoi(strtok(NULL, " "));
                        break;
                    case 'c':
                        printf("Cleared.\n");
                        break;
                    default:
                        printf("Invalid operator.\n");
                }
            }
            num2 = num1;
            token = strtok(NULL, " ");
        }
        printf("Result: %lf\n", num1);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);
    }while(repeat == 'y' || repeat == 'Y');
    return 0;
}