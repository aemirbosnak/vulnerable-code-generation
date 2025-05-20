//FormAI DATASET v1.0 Category: Computer Biology ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DIM 3       //Size of the matrix (in this case NxN matrix)

int main()
{
    int matrix[DIM][DIM],i,j,k;

    for(i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            printf("Enter the value at (%d,%d):",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("The matrix you entered is:\n");
    for(i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    printf("The determinant of the matrix is:");
    if(DIM==2)
    {
        printf("%d",matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]);
    }
    else if(DIM==3)
    {
        int det=(matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[0][1]*matrix[1][2]*matrix[2][0])+(matrix[0][2]*matrix[1][0]*matrix[2][1])
                -(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[0][0]*matrix[1][2]*matrix[2][1])-(matrix[0][1]*matrix[1][0]*matrix[2][2]);
        printf("%d\n",det);
    }
    else
    {
        printf("This program is only designed for 2x2 and 3x3 matrices.");
    }

    printf("The transpose of the matrix is:\n");
    for(i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }

    printf("The inverse of the matrix is:\n");
    if(DIM==2)
    {
        int det=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        printf("%f %f\n",(matrix[1][1]/(float)det),((-1)*matrix[0][1]/(float)det));
        printf("%f %f\n",((-1)*matrix[1][0]/(float)det),(matrix[0][0]/(float)det));
    }
    else if(DIM==3)
    {
        int det=(matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[0][1]*matrix[1][2]*matrix[2][0])+(matrix[0][2]*matrix[1][0]*matrix[2][1])
                -(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[0][0]*matrix[1][2]*matrix[2][1])-(matrix[0][1]*matrix[1][0]*matrix[2][2]);
        printf("%f %f %f\n",((matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])/((float)det)),((-1)*(matrix[0][1]*matrix[2][2]-matrix[0][2]*matrix[2][1])/((float)det)),((matrix[0][1]*matrix[1][2]-matrix[0][2]*matrix[1][1])/((float)det)));
        printf("%f %f %f\n",((-1)*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])/((float)det)),((matrix[0][0]*matrix[2][2]-matrix[0][2]*matrix[2][0])/((float)det)),((-1)*(matrix[0][0]*matrix[1][2]-matrix[0][2]*matrix[1][0])/((float)det)));
        printf("%f %f %f\n",((matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0])/((float)det)),((-1)*(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0])/((float)det)),((matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0])/((float)det)));
    }
    else
    {
        printf("This program is only designed for 2x2 and 3x3 matrices.");
    }

    printf("The adjoint of the matrix is:\n");
    if(DIM==2)
    {
        printf("%d %d\n%d %d",matrix[1][1],((-1)*matrix[0][1]),((-1)*matrix[1][0]),matrix[0][0]);
    }
    else if(DIM==3)
    {
        printf("%d %d %d\n%d %d %d\n%d %d %d",((matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])),((-1)*(matrix[0][1]*matrix[2][2]-matrix[0][2]*matrix[2][1])),((matrix[0][1]*matrix[1][2]-matrix[0][2]*matrix[1][1])),
                ((-1)*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])),((matrix[0][0]*matrix[2][2]-matrix[0][2]*matrix[2][0])),((-1)*(matrix[0][0]*matrix[1][2]-matrix[0][2]*matrix[1][0])),
                ((matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0])),((-1)*(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0])),((matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0])));
    }
    else
    {
        printf("This program is only designed for 2x2 and 3x3 matrices.");
    }

    return 0;
}