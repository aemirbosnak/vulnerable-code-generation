//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int rows,cols,i,j,k,x,y,z;
    float alpha,beta;
    FILE *fp;
    char filename[20];
    printf("Enter the name of the image file: ");
    scanf("%s",filename);
    fp=fopen(filename,"rb");
    if(fp==NULL)
    {
        printf("Error opening file!\n");
        exit(0);
    }
    fseek(fp,18,0);
    fread(&rows,4,1,fp);
    fread(&cols,4,1,fp);
    printf("Enter the value of alpha (0<=alpha<=1): ");
    scanf("%f",&alpha);
    printf("Enter the value of beta (0<=beta<=1): ");
    scanf("%f",&beta);
    printf("Enter the option:\n1 for flipping the image\n2 for changing brightness/contrast\n");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cols;j++)
                {
                    fseek(fp,54+i*cols+j,0);
                    fread(&x,4,1,fp);
                    fread(&y,4,1,fp);
                    if(x==0)
                    {
                        x=255;
                    }
                    else
                    {
                        x=0;
                    }
                    if(y==0)
                    {
                        y=255;
                    }
                    else
                    {
                        y=0;
                    }
                    fseek(fp,54+i*cols+j,0);
                    fwrite(&x,4,1,fp);
                    fwrite(&y,4,1,fp);
                }
            }
            printf("Image flipped successfully!\n");
            break;
        case 2:
            for(i=0;i<rows;i++)
            {
                for(j=0;j<cols;j++)
                {
                    fseek(fp,54+i*cols+j,0);
                    fread(&x,4,1,fp);
                    fread(&y,4,1,fp);
                    fread(&z,4,1,fp);
                    x=(int)((float)x*alpha);
                    y=(int)((float)y*beta);
                    z=(int)((float)z*beta);
                    if(x>255)
                    {
                        x=255;
                    }
                    if(y>255)
                    {
                        y=255;
                    }
                    if(z>255)
                    {
                        z=255;
                    }
                    if(x<0)
                    {
                        x=0;
                    }
                    if(y<0)
                    {
                        y=0;
                    }
                    if(z<0)
                    {
                        z=0;
                    }
                    fseek(fp,54+i*cols+j,0);
                    fwrite(&x,4,1,fp);
                    fwrite(&y,4,1,fp);
                    fwrite(&z,4,1,fp);
                }
            }
            printf("Image brightness/contrast changed successfully!\n");
            break;
        default:
            printf("Invalid option!\n");
    }
    fclose(fp);
    return 0;
}