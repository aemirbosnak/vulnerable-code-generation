//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 10
int matrix1[MAX][MAX], matrix2[MAX][MAX], ans[MAX][MAX];
int row1, col1, row2, col2, row_ans, col_ans;
struct args{
    int i,j;
};
void *matrix_multiply(void *arg){
    struct args *data = arg;
    int sum = 0;
    for(int k=0; k<col1; k++){
        sum += matrix1[data->i][k] * matrix2[k][data->j];
    }
    ans[data->i][data->j] = sum;
    pthread_exit(NULL);
}
void matrix_input(){
    printf("\nEnter rows and columns of first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("\nEnter elements of first matrix: ");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nEnter rows and columns of second matrix: ");
    scanf("%d %d", &row2, &col2);
    printf("\nEnter elements of second matrix: ");
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }
}
void matrix_display(int matrix[MAX][MAX], int row, int col){
    printf("\nThe Matrix:\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    matrix_input();
    if(col1 != row2){
        printf("\nMultiplication of matrices not possible!\n");
        exit(0);
    }
    row_ans = row1;
    col_ans = col2;
    for(int i=0; i<row_ans; i++){
        for(int j=0; j<col_ans; j++){
            struct args *data = (struct args*) malloc(sizeof(struct args));
            data->i = i;
            data->j = j;
            pthread_t thread_id;
            pthread_attr_t attributes;
            pthread_attr_init(&attributes);
            pthread_create(&thread_id, &attributes, matrix_multiply, data);
            pthread_join(thread_id, NULL);
        }
    }
    printf("\nResultant Matrix:\n");
    matrix_display(ans, row_ans, col_ans);
    return 0;
}