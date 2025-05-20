//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_LOCATIONS 20

//Structure Definition
struct location{
  char name[20];
  float latitude;
  float longitude;
};

//Function Declaration
int read_input_file(char[], struct location[]);
void print_menu();
void print_locations(struct location[], int);
void get_directions(struct location[], int);

int main(){

  //Declaration of Variables
  int num_locations;
  struct location locations[MAX_LOCATIONS];
  char input_file[50];

  printf("\nWelcome to GPS Navigation Simulation!\n");

  printf("\nEnter the input file name: ");
  scanf("%s", &input_file);

  //Reading input file
  num_locations = read_input_file(input_file, locations);

  //Printing menu
  print_menu();

  //Getting user input
  int option;
  printf("\nEnter option: ");
  scanf("%d", &option);

  while(option!=4){

    switch(option){

      case 1:
        print_locations(locations, num_locations);
        break;

      case 2:
        get_directions(locations, num_locations);
        break;

      case 3:
        print_menu();
        break;

      default:
        printf("\nInvalid option. Please try again.\n");
    }

    printf("\nEnter option: ");
    scanf("%d", &option);
  }

  return 0;
}

//Function to read input file
int read_input_file(char file_name[], struct location locations[]){

  FILE *fptr;

  fptr = fopen(file_name, "r");

  if(fptr == NULL){
    printf("\nError: Unable to open file.\n");
    exit(EXIT_FAILURE);
  }

  char line[50];
  int count = 0;

  while(fgets(line, sizeof(line), fptr)){

      char *token = strtok(line, ",");

      strcpy(locations[count].name, token);
      locations[count].latitude = atof(strtok(NULL, ","));
      locations[count].longitude = atof(strtok(NULL, ","));

      count++;
  }

  fclose(fptr);

  printf("\n%d locations found in the input file.\n", count);

  return count;
}

//Function to print menu
void print_menu(){
  printf("\n------------------MENU------------------");
  printf("\n1. View all available locations");
  printf("\n2. Get directions between locations");
  printf("\n3. Display menu");
  printf("\n4. Exit");
  printf("\n----------------------------------------\n");
}

//Function to print all locations
void print_locations(struct location locations[], int num_locations){

  printf("\nLocations:\n");

  for(int i=0; i<num_locations; i++){
    printf("%d. %s\n", i+1, locations[i].name);
  }
}

//Function to get directions between locations
void get_directions(struct location locations[], int num_locations){

  //Getting user input
  int start_index, end_index;
  printf("\nEnter starting location: ");
  scanf("%d", &start_index);

  printf("\nEnter ending location: ");
  scanf("%d", &end_index);

  //Checking if indices are valid
  if(start_index > num_locations || end_index > num_locations || start_index < 1 || end_index < 1){
    printf("\nInvalid indices. Please try again.\n");
    return;
  }

  //Calculating distance
  float lat1 = locations[start_index-1].latitude;
  float long1 = locations[start_index-1].longitude;
  float lat2 = locations[end_index-1].latitude;
  float long2 = locations[end_index-1].longitude;

  float distance = sqrt(pow((lat2 - lat1), 2) + pow((long2 - long1), 2));

  printf("\nDistance between %s and %s is %.2f kms.\n", locations[start_index-1].name, locations[end_index-1].name, distance);

}