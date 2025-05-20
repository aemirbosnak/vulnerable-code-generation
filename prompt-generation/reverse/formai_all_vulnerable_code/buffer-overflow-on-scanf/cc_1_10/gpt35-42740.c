//FormAI DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>

// Defining movement functions
void forward(){
    printf("The Robot moves forward.\n");
}
void backward(){
    printf("The Robot moves backward.\n");
}
void left(){
    printf("The Robot turns left.\n");
}
void right(){
    printf("The Robot turns right.\n");
}

int main(){

    // Start of program
    printf("Welcome to the C Robot Move Control Program!\n");
    printf("Enter a direction to move:\n");
    
    char direction;
    scanf("%c", &direction);

    // Sensible deduction of direction
    if(direction == 'F' || direction == 'f'){
        forward();
    }
    else if(direction == 'B' || direction == 'b'){
        backward();
    }
    else if(direction == 'L' || direction == 'l'){
        left();
    }
    else if(direction == 'R' || direction == 'r'){
        right();
    }
    else{
        printf("You have entered an invalid direction. Please try again.\n");
        main();
        return 0;
    }

    // End of program
    printf("Your desired direction has been executed successfully!\n");
    printf("Thank you for using the C Robot Move Control Program. Goodbye!\n");

    return 0;
}