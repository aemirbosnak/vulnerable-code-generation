//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct stock{
    char name[20];
    float current_price;
    float previous_price;
    char fluctuation_sign;
    float fluctuation_percent;
};

void printStock(struct stock s){
    printf("%s\t", s.name);
    printf("%.2f\t\t", s.current_price);
    printf("%.2f\t\t", s.previous_price);
    printf("%c\t", s.fluctuation_sign);
    printf("%.2f%%\n", s.fluctuation_percent);
}

int main(){
    struct stock stocks[5];
    strcpy(stocks[0].name, "ABC");
    strcpy(stocks[1].name, "DEF");
    strcpy(stocks[2].name, "GHI");
    strcpy(stocks[3].name, "JKL");
    strcpy(stocks[4].name, "MNO");

    srand(time(0));

    int i;
    for(i = 0; i < 5; i++){
        stocks[i].current_price = rand() % 101;
        stocks[i].previous_price = rand() % 101;

        if(stocks[i].current_price >= stocks[i].previous_price){
            stocks[i].fluctuation_sign = '+';
            stocks[i].fluctuation_percent = ((stocks[i].current_price - stocks[i].previous_price)/stocks[i].previous_price)*100;
        }
        else{
            stocks[i].fluctuation_sign = '-';
            stocks[i].fluctuation_percent = ((stocks[i].previous_price - stocks[i].current_price)/stocks[i].previous_price)*100;
        }
    }

    printf("Stock\tCurrent Price\tPrevious Price\tChange\t\tChange Percentage\n");

    for(i = 0; i < 5; i++){
        printStock(stocks[i]);
    }

    return 0;
}