//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CITIES 5
#define MAX_TEMPERATURES 10

typedef struct{
    char name[20];
    int temperature[MAX_TEMPERATURES];
    int index;
}City;

void initialize_cities(City cities[], int num_cities){
    for(int i=0;i<num_cities;i++){
        sprintf(cities[i].name,"City %d",i+1);
        cities[i].index = i;
    }
}

void generate_weather(City city){
    for(int i=0;i<MAX_TEMPERATURES;i++){
        city.temperature[i] = rand()%30 + 1;
    }
}

void print_weather(City city){
    printf("Weather in %s:\n",city.name);
    for(int i=0;i<MAX_TEMPERATURES;i++){
        printf("%d ",city.temperature[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    City cities[MAX_CITIES];
    int num_cities = 0;
    int choice;

    do{
        printf("1. Add City\n2. Show Weather\n3. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(num_cities < MAX_CITIES){
                    printf("Enter city name: ");
                    scanf("%s",cities[num_cities].name);
                    initialize_cities(cities,num_cities+1);
                    num_cities++;
                }else{
                    printf("Maximum number of cities reached.\n");
                }
                break;

            case 2:
                printf("Enter city index: ");
                scanf("%d",&choice);
                if(choice >= 1 && choice <= num_cities){
                    print_weather(cities[choice-1]);
                }else{
                    printf("Invalid city index.\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }while(1);

    return 0;
}