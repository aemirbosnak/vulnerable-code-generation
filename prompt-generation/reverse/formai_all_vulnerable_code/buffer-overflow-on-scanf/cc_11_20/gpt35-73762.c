//FormAI DATASET v1.0 Category: Matrix operations ; Style: curious
#include<stdio.h>

/* Curious Matrix Operations */

int main() { 

  int rows, cols, i, j;
  float det=1;

  printf("Enter the number of rows and columns of the matrix: ");
  scanf("%d %d", &rows, &cols); 
  
  float matrix[rows][cols], transpose[cols][rows], inverse[rows][cols], adj[rows][cols];
  
  printf("Enter the elements of the matrix: \n");	 
  
  for(i=0;i<rows;i++) {
    
    for(j=0;j<cols;j++) {
      
      printf("Matrix[%d][%d]: ",i+1,j+1);
      scanf("%f",&matrix[i][j]);
      
    }
    
  }
  
  printf("The given matrix is: \n");
  
  for(i=0;i<rows;i++) {
    
    for(j=0;j<cols;j++) {
      
      printf("%.2f ", matrix[i][j]);
      
    }
    printf("\n");
    
  }
  
  /* Determinant of the matrix */
  
  if(rows==cols) {
    
    for(i=0;i<rows;i++)
      
      det=det*matrix[i][i];
      
    printf("The determinant of the matrix is: %.2f\n",det);
      
  }
  
  else {
    
    printf("Determinant only applicable for square matrices!\n");
    
  }
  
  /* Transpose of the matrix */
  
  printf("The transpose of the matrix is: \n");
  
  for(i=0;i<cols;i++) {
    
    for(j=0;j<rows;j++) {
      
      transpose[i][j]=matrix[j][i];
      printf("%.2f ",transpose[i][j]);
      
    }
    printf("\n");
    
  }
  
  /* Inverse of the matrix */
  
  if(rows==cols) {
    
    for(i=0;i<rows;i++) {
      
      for(j=0;j<cols;j++) {
        
        adj[i][j] = (((((i+j)%2)==0)?1:-1) * ((matrix[(j+1)%rows][(i+1)%cols] * matrix[(j+2)%rows][(i+2)%cols]) - (matrix[(j+1)%rows][(i+2)%cols] * matrix[(j+2)%rows][(i+1)%cols]))); 
        inverse[i][j] = adj[i][j]/det;
        
      }
    }
    
    printf("The inverse of the matrix is: \n");
    
    for(i=0;i<rows;i++) {
    
      for(j=0;j<cols;j++) {
      
        printf("%.2f ", inverse[i][j]);
      
      }
      printf("\n");
    
    }
    
  }
  
  else {
    
    printf("Inverse only applicable for square matrices!\n");
    
  }
  
  return 0;  
}