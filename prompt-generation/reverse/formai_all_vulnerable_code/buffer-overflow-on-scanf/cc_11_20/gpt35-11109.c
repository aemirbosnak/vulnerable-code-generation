//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>

//initialize database array
int database[10][2] = {
    {1, 45},
    {2, 34},
    {3, 22},
    {4, 67},
    {5, 48},
    {6, 74},
    {7, 12},
    {8, 39},
    {9, 52},
    {10, 81}
};
int num_of_rows = 10;

int main() {
    int choice, row_num, new_value, index;
    
    printf("Welcome to database simulation program!!");
    
    do {
        printf("\n\nEnter your choice:\n");
        printf("1. View all data\n");
        printf("2. Search by row number\n");
        printf("3. Update a row\n");
        printf("4. Add a new row\n");
        printf("5. Delete a row\n");
        printf("6. Exit program\n\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n\nAll data in database:\n");
                printf("---------------------------\n");
                for(int i=0; i<num_of_rows; i++) {
                    printf("| %d | %d |\n", database[i][0], database[i][1]);
                }
                printf("---------------------------\n");
                break;
            case 2:
                printf("\n\nEnter row number to search:\n");
                scanf("%d", &row_num);
                index = -1;
                for(int i=0; i<num_of_rows; i++) {
                    if(database[i][0] == row_num) {
                        index = i;
                        break;
                    }
                }
                if(index != -1) {
                    printf("\nRow found!!\n");
                    printf("| %d | %d |\n", database[index][0], database[index][1]);
                }
                else {
                    printf("\nRow not found!!\n");
                }
                break;
            case 3:
                printf("\n\nEnter row number to update:\n");
                scanf("%d", &row_num);
                index = -1;
                for(int i=0; i<num_of_rows; i++) {
                    if(database[i][0] == row_num) {
                        index = i;
                        break;
                    }
                }
                if(index != -1) {
                    printf("\nRow found!!\n");
                    printf("Enter new value for row:\n");
                    scanf("%d", &new_value);
                    database[index][1] = new_value;
                    printf("\nRow updated successfully!!\n");
                    printf("| %d | %d |\n", database[index][0], database[index][1]);
                }
                else {
                    printf("\nRow not found!!\n");
                }
                break;
            case 4:
                if(num_of_rows < 10) {
                    printf("\n\nEnter row number and value separated by a space:\n");
                    scanf("%d %d", &row_num, &new_value);
                    database[num_of_rows][0] = row_num;
                    database[num_of_rows][1] = new_value;
                    num_of_rows++;
                    printf("\nNew row added successfully!!\n");
                }
                else {
                    printf("\nDatabase is full!!\n");
                }
                break;
            case 5:
                printf("\n\nEnter row number to delete:\n");
                scanf("%d", &row_num);
                index = -1;
                for(int i=0; i<num_of_rows; i++) {
                    if(database[i][0] == row_num) {
                        index = i;
                        break;
                    }
                }
                if(index != -1) {
                    printf("\nRow found!!\n");
                    for(int i=index; i<num_of_rows-1; i++) {
                        database[i][0] = database[i+1][0];
                        database[i][1] = database[i+1][1];
                    }
                    num_of_rows--;
                    printf("\nRow deleted successfully!!\n");
                }
                else {
                    printf("\nRow not found!!\n");
                }
                break;
            case 6:
                printf("\n\nThank you for using database simulation program!!\n");
                break;
            default:
                printf("\n\nInvalid choice!!\n");
        }
    } while(choice != 6);
    
    return 0;
}