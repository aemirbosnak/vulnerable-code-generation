//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max (inclusive)
int generate_random_number(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to check if the given cell number is valid or not
int is_valid_cell(int cell_number, int rows, int cols){
    if(cell_number>=0 && cell_number<rows*cols){
        return 1;
    }
    return 0;
}

// Function to initialize the table with random numbers
void initialize_table(int *table, int rows, int cols){
    for(int i=0; i<rows*cols; i++){
        table[i] = generate_random_number(1,9);
    }
}

// Function to display the table
void display_table(int *table, int rows, int cols){
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            int index = row*cols + col;
            printf("%d ", table[index]);
        }
        printf("\n");
    }
}

// Function to get the cell number of the given row and column number
int get_cell_number(int row, int col, int cols){
    return row*cols + col;
}

// Function to get the row number of the given cell number
int get_row_number(int cell_number, int cols){
    return cell_number/cols;
}

// Function to get the column number of the given cell number
int get_col_number(int cell_number, int cols){
    return cell_number%cols;
}

// Function to get the neighbours of the given cell
int *get_neighbours(int *table, int cell_number, int rows, int cols){
    static int neighbours[8];

    int row = get_row_number(cell_number, cols);
    int col = get_col_number(cell_number, cols);

    int top_left = get_cell_number(row-1, col-1, cols);
    int top = get_cell_number(row-1, col, cols);
    int top_right = get_cell_number(row-1, col+1, cols);
    int left = get_cell_number(row, col-1, cols);
    int right = get_cell_number(row, col+1, cols);
    int bottom_left = get_cell_number(row+1, col-1, cols);
    int bottom = get_cell_number(row+1, col, cols);
    int bottom_right = get_cell_number(row+1, col+1, cols);

    int n = 0;
    if(is_valid_cell(top_left, rows, cols)){
        neighbours[n++] = table[top_left];
    }
    if(is_valid_cell(top, rows, cols)){
        neighbours[n++] = table[top];
    }
    if(is_valid_cell(top_right, rows, cols)){
        neighbours[n++] = table[top_right];
    }
    if(is_valid_cell(left, rows, cols)){
        neighbours[n++] = table[left];
    }
    if(is_valid_cell(right, rows, cols)){
        neighbours[n++] = table[right];
    }
    if(is_valid_cell(bottom_left, rows, cols)){
        neighbours[n++] = table[bottom_left];
    }
    if(is_valid_cell(bottom, rows, cols)){
        neighbours[n++] = table[bottom];
    }
    if(is_valid_cell(bottom_right, rows, cols)){
        neighbours[n++] = table[bottom_right];
    }

    return neighbours;
}

// Function to get the sum of the neighbours of a given cell
int sum_neighbours(int *table, int cell_number, int rows, int cols){
    int *neighbours = get_neighbours(table, cell_number, rows, cols);
    int sum = 0;
    for(int i=0; i<8; i++){
        sum += neighbours[i];
    }
    return sum;
}

// Function to get the max neighbour sum among all cells in the table
int get_max_neighbours_sum(int *table, int rows, int cols){
    int max_sum = 0;
    for(int i=0; i<rows*cols; i++){
        int sum = sum_neighbours(table, i, rows, cols);
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    return max_sum;
}

// Function to play the game
void play_game(int rows, int cols){
    int table[rows*cols];
    initialize_table(table, rows, cols);

    printf("Initial table:\n");
    display_table(table, rows, cols);
    printf("\n");

    int max_neighbours_sum = get_max_neighbours_sum(table, rows, cols);

    printf("Max neighbours sum: %d\n", max_neighbours_sum);
}

int main(){
    srand(time(0));    // Initialize random number generator 

    printf("Welcome to the Table Game!\n");
    printf("--------------------------\n");
    printf("\n");

    printf("Enter the number of rows in the table: ");
    int rows;
    scanf("%d", &rows);

    printf("Enter the number of columns in the table: ");
    int cols;
    scanf("%d", &cols);

    printf("\n");

    play_game(rows, cols);

    return 0;
}