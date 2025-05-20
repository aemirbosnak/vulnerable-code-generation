//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct product {
    char name[50];
    int code;
    float price;
    int quantity;
}p[MAX];

int main() {
    int choice,i;
    char ch;
    FILE *fp;

    printf("\nEnter 1 to add product\n2 to modify product\n3 to delete product\n4 to display product\n5 to exit\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            fp=fopen("product.dat","ab");
            printf("\nEnter product name: ");
            scanf("%s",&p[0].name);
            printf("\nEnter product code: ");
            scanf("%d",&p[0].code);
            printf("\nEnter product price: ");
            scanf("%f",&p[0].price);
            printf("\nEnter product quantity: ");
            scanf("%d",&p[0].quantity);
            fwrite(&p[0],sizeof(p[0]),1,fp);
            printf("\nProduct added successfully");
            fclose(fp);
            break;

        case 2:
            fp=fopen("product.dat","rb+");
            printf("\nEnter product code to modify: ");
            scanf("%d",&ch);
            fseek(fp,0,2);
            for(i=0;i<MAX;i++) {
                fread(&p[i],sizeof(p[i]),1,fp);
                if(p[i].code==ch) {
                    printf("\nEnter new product name: ");
                    scanf("%s",&p[i].name);
                    printf("\nEnter new product price: ");
                    scanf("%f",&p[i].price);
                    printf("\nEnter new product quantity: ");
                    scanf("%d",&p[i].quantity);
                    fseek(fp,-sizeof(p[i]),1);
                    fwrite(&p[i],sizeof(p[i]),1,fp);
                    printf("\nProduct modified successfully");
                }
            }
            fclose(fp);
            break;

        case 3:
            fp=fopen("product.dat","rb+");
            printf("\nEnter product code to delete: ");
            scanf("%d",&ch);
            fseek(fp,0,2);
            for(i=0;i<MAX;i++) {
                fread(&p[i],sizeof(p[i]),1,fp);
                if(p[i].code==ch) {
                    fseek(fp,-sizeof(p[i]),1);
                    memset(&p[i],0,sizeof(p[i]));
                    printf("\nProduct deleted successfully");
                }
            }
            fclose(fp);
            break;

        case 4:
            fp=fopen("product.dat","rb");
            printf("\nProduct code\tProduct name\tPrice\tQuantity\n");
            while(fread(&p[i],sizeof(p[i]),1,fp)!=0) {
                printf("%d\t%s\t%.2f\t%d\n",p[i].code,p[i].name,p[i].price,p[i].quantity);
            }
            fclose(fp);
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice");
    }

    return 0;
}