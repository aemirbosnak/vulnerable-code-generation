//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //declare variables to store user input
    char name[20];
    int age, luckyNumber;

    //initialize random seed
    srand(time(NULL));

    //welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", &name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your lucky number (between 1 and 10): ");
    scanf("%d", &luckyNumber);

    //generate random fortune based on user inputs
    int randomNum = rand() % 10 + 1;
    printf("\n\n\n");

    if (randomNum == 1)
    {
        printf("Dear %s, your lucky number %d implies that you are very full of life and energy.\n", name, luckyNumber);
        printf("Your age of %d years is a perfect reflection of how far you have come on your life's journey.\n", age);
        printf("You need to keep up with the good energy in order to achieve your desired goals.\n");
    }
    else if (randomNum == 2)
    {
        printf("Dear %s, your lucky number %d suggests that you are a creative individual who likes to think outside the box.\n", name, luckyNumber);
        printf("Your age of %d years is not just a number- it is a reflection of all the experiences and lessons you have gathered in your life.\n", age);
        printf("You have the potential to achieve great things in your life- keep nurturing your creativity and individuality!\n");
    }
    else if (randomNum == 3)
    {
        printf("Dear %s, your lucky number %d suggests that you are a very grounded and stable person.\n", name, luckyNumber);
        printf("Your age of %d years helps you to form strong foundations and structures that will help you achieve success in the future.\n", age);
        printf("Your personality is your winning trophy- keep on building and enhancing it in order to shine bright like a diamond!\n");
    }
    else if (randomNum == 4)
    {
        printf("Dear %s, your lucky number %d suggests that you are a self-sufficient person who does not rely on others for your success.\n", name, luckyNumber);
        printf("Your age of %d years is a testament to the fact that you have accomplished a lot on your own so far, and that there are many more successes in store for you!\n", age);
        printf("You should always stay true to yourself and keep on working hard to achieve your dreams!\n");
    }
    else if (randomNum == 5)
    {
        printf("Dear %s, your lucky number %d suggests that you are very adaptable and can thrive in a variety of situations!\n", name, luckyNumber);
        printf("Your age of %d years reflects all the experiences and lessons you have gathered in your life so far- use them as a stepping stone\n", age);
        printf("You will be successful in conquering all the challenges that come in your way, just keep on being adaptable and flexible!\n");
    }
    else if (randomNum == 6)
    {
        printf("Dear %s, your lucky number %d suggests that you have a deep connection with nature and love to explore the world.\n", name, luckyNumber);
        printf("Your age of %d years is a representation of all the beautiful memories and bonds you have cherished so far.\n", age);
        printf("There is infinite beauty and adventure waiting for you- keep exploring and enjoying the wonders of nature!\n");
    }
    else if (randomNum == 7)
    {
        printf("Dear %s, your lucky number %d suggests that you are very intelligent and have a deep passion for learning.\n", name, luckyNumber);
        printf("Your age of %d years reflects all the valuable knowledge and wisdom you have gathered so far.\n", age);
        printf("Keep on learning, expanding your horizons and discovering new facets of yourself and the world- there are limitless possibilities waiting for you!\n");
    }
    else if (randomNum == 8)
    {
        printf("Dear %s, your lucky number %d suggests that you are a passionate and enthusiastic person who loves to inspire others.\n", name, luckyNumber);
        printf("Your age of %d years reflects your experience, wisdom and maturity- all of which you can channel to inspire people and make a positive difference in their lives!\n", age);
        printf("You are an achiever- keep inspiring the world with your passion and energy!\n");
    }
    else if (randomNum == 9)
    {
        printf("Dear %s, your lucky number %d suggests that you are a very kind and empathetic person who always puts others first.\n", name, luckyNumber);
        printf("Your age of %d years is all about the rich experiences, wonderful memories and valuable lessons you have accumulated so far.\n", age);
        printf("Being kind, compassionate and empathetic is the way to go- keep on shining with your selfless deeds and heartfelt gestures!\n");
    }
    else if (randomNum == 10)
    {
        printf("Dear %s, your lucky number %d suggests that you are very adventurous, and love to try out new things and take risks!\n", name, luckyNumber);
        printf("Your age of %d years reflects all the unforgettable experiences, adventurous memories, and daring acts you have taken on so far.\n", age);
        printf("You are fearlessly unique- keep being adventurous, taking risks and exploring new territories!\n");
    }
    else{
        printf("Uh, something went wrong! Sorry, it's not you, it's me. :(");
        return 1;
    } 

    return 0;
}